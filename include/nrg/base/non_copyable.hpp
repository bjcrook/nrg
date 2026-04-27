////////////////////////////////////////////////////////////////////////////////
/// @Copyright (c) 2026 Brian Crook. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef NRG_BASE_NON_COPYABLE_HPP
#define NRG_BASE_NON_COPYABLE_HPP

namespace nrg {
class non_copyable {
 protected:
  non_copyable() = default;
  ~non_copyable() = default;

  non_copyable(const non_copyable&) = delete;
  non_copyable& operator=(const non_copyable&) = delete;
};
}  // namespace nrg

#endif  // NRG_BASE_NON_COPYABLE_HPP
