//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_CSCD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_CSCD_HPP_INCLUDED

#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sind.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( cscd_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return cscd(a0, tag::big_);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( cscd_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::scalar_ < bd::unspecified_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A1 const&) const BOOST_NOEXCEPT
    {
      return if_nan_else( is_nez(a0)&&is_flint(a0*Ratio<A0,1,180>())
                        , rec(sind(a0, tag::big_)));
    }
  };
  BOOST_DISPATCH_OVERLOAD ( cscd_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 const& a0) const BOOST_NOEXCEPT
    {
      return rec(fast_(sind)(a0));
    }
  };
} } }


#endif
