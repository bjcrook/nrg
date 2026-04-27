////////////////////////////////////////////////////////////////////////////////
/// @Copyright (c) 2026 Brian Crook. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>

#include <nrg/container/spsc_queue.hpp>

TEST(SpscQueueTest, InitalizationTests) {
  /// @brief Show that queues initialize with the requested capacity or the
  /// capacity nearest to the next power of 2 and that the move and copy ctors
  /// are deleted.

  nrg::spsc_queue<int> queue1{8};
  EXPECT_EQ(queue1.capacity(), 8);

  // auto queue1_copy = queue1;  // Copy ctor deleted.
  // auto queue1_move = std::move(queue1);  // Move ctor deleted.

  nrg::spsc_queue<int> queue2{9};
  EXPECT_EQ(queue2.capacity(), 16);

  nrg::spsc_queue<int> queue3{15};
  EXPECT_EQ(queue2.capacity(), 16);
}
