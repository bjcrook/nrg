################################################################################
# Copyright (c) 2026 Brian Crook. All rights reserved.
################################################################################

target_sources(
   nrg.tests
   PRIVATE
      spsc_queue_tests.cpp
)

target_link_libraries(
   nrg.tests
   PRIVATE
      GTest::gtest
      GTest::gtest_main
      nrg::nrg
)
