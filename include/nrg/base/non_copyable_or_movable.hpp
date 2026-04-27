////////////////////////////////////////////////////////////////////////////////
/// @Copyright (c) 2026 Brian Crook. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef NRG_BASE_NON_COPYABLE_OR_MOVABLE_HPP
#define NRG_BASE_NON_COPYABLE_OR_MOVABLE_HPP

#include "nrg/base/non_copyable.hpp"
#include "nrg/base/non_movable.hpp"

namespace nrg {
class non_copyable_or_movable : non_copyable, non_movable {
 protected:
  non_copyable_or_movable() = default;
  ~non_copyable_or_movable() = default;
};
}  // namespace nrg

#endif  // NRG_BASE_NON_COPYABLE_OR_MOVABLE_HPP
