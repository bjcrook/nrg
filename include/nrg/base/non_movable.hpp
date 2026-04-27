////////////////////////////////////////////////////////////////////////////////
/// @Copyright (c) 2026 Brian Crook. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef NRG_BASE_NON_MOVABLE_HPP
#define NRG_BASE_NON_MOVABLE_HPP

namespace nrg {
class non_movable {
 protected:
  non_movable() = default;
  ~non_movable() = default;

  non_movable(non_movable&&) = delete;
  non_movable& operator=(non_movable&&) = delete;
};
}  // namespace nrg

#endif  // NRG_BASE_NON_MOVABLE_HPP
