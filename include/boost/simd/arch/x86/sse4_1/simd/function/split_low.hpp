//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_SPLIT_LOW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_SPLIT_LOW_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( split_low_, (typename A0), bs::sse4_1_
                          , bs::pack_<bd::int8_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE bd::upgrade_t<A0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvtepi8_epi16(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( split_low_, (typename A0), bs::sse4_1_
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE bd::upgrade_t<A0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvtepi16_epi32(a0);
    }
  };
} } }

#endif
