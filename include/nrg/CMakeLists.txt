################################################################################
# Copyright (c) 2026 Brian Crook. All rights reserved.
################################################################################

target_sources(
  nrg
  PUBLIC
    FILE_SET nrg_headers
      TYPE HEADERS
      FILES
        container/spsc_queue.hpp

        base/non_copyable.hpp
        base/non_copyable_or_movable.hpp
        base/non_movable.hpp
)
