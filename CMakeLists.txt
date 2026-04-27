################################################################################
# Copyright (c) 2026 Brian Crook. All rights reserved.
################################################################################

cmake_minimum_required(VERSION 4.2)

project(
  nrg
  VERSION 0.1.0
  LANGUAGES CXX
)

option(NRG_BUILD_TESTS "Build library tests" ON)

add_library(nrg INTERFACE)

target_sources(
  nrg
  PUBLIC FILE_SET nrg_headers TYPE HEADERS BASE_DIRS include
)

add_subdirectory(include/nrg)

# Testing
if(NRG_BUILD_TESTS)
  add_library(nrg::nrg ALIAS nrg)

  enable_testing()
  find_package(GTest REQUIRED)

  add_executable(nrg.tests)
  add_subdirectory(tests/nrg)

  include(GoogleTest)
  gtest_discover_tests(nrg.tests)
endif()
