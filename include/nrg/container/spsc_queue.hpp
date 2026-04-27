////////////////////////////////////////////////////////////////////////////////
/// @Copyright (c) 2026 Brian Crook. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef NRG_CONTAINER_SPSC_QUEUE_HPP
#define NRG_CONTAINER_SPSC_QUEUE_HPP

#include <atomic>
#include <bit>
#include <memory>
#include <type_traits>

#include "nrg/base/non_copyable_or_movable.hpp"

namespace nrg {
template <typename T>
class spsc_queue final : non_copyable_or_movable {
  static_assert(std::is_trivial_v<T>, "T must be a trivial type.");

 public:
  spsc_queue(std::size_t minimum_capacity)
      : capacity_{std::bit_ceil(minimum_capacity)} {
    buffer_ = std::make_unique<T[]>(capacity_);
  }

  bool push(const T& element) {
    auto tail_index = tail_.load(std::memory_order_relaxed);

    if (tail_index - head_.load(std::memory_order_acquire) > capacity_ - 1) {
      return false;  // Queue is full.
    }

    buffer_[tail_index & (capacity_ - 1)] = element;
    tail_.store(tail_index + 1, std::memory_order_release);
    return true;
  }

  bool pop(T& element) {
    auto head_index = head_.load(std::memory_order_relaxed);

    if (head_index == tail_.load(std::memory_order_acquire)) {
      return false;  // Queue is empty.
    }

    element = buffer_[head_index & (capacity_ - 1)];
    head_.store(head_index + 1, std::memory_order_release);
    return true;
  }

  bool pop() {
    auto head_index = head_.load(std::memory_order_relaxed);

    if (head_index == tail_.load(std::memory_order_acquire)) {
      return false;  // Queue is empty.
    }

    head_.store(head_index + 1, std::memory_order_release);
    return true;
  }

  bool empty() const {
    return tail_.load(std::memory_order_acquire) ==
           head_.load(std::memory_order_acquire);
  }

  bool full() const {
    return (tail_.load(std::memory_order_acquire) -
            head_.load(std::memory_order_acquire)) > (capacity_ - 1);
  }

  std::size_t capacity() const { return capacity_; }

 private:
  std::size_t capacity_;
  std::unique_ptr<T[]> buffer_;
  alignas(64) std::atomic<std::size_t> head_{0};
  alignas(64) std::atomic<std::size_t> tail_{0};
};
}  // namespace nrg

#endif  // NRG_CONTAINER_SPSC_QUEUE_HPP
