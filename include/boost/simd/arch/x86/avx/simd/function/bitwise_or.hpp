//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_BITWISE_OR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_BITWISE_OR_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( bitwise_or_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
      {
        return _mm256_or_pd(a0, a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD( bitwise_or_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
      {
        return _mm256_or_ps(a0, a1);
      }
   };
} } }

#endif
