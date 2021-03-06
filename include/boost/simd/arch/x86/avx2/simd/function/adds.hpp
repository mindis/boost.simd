//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_ADDS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_ADDS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( adds_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_< bd::int16_<A0>, bs::avx_>
                          , bs::pack_< bd::int16_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const
      {
        return _mm256_adds_epi16(a0,a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD( adds_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_< bd::int8_<A0>, bs::avx_>
                          , bs::pack_< bd::int8_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const
      {
        return _mm256_adds_epi8(a0,a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD( adds_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_< bd::uint16_<A0>, bs::avx_>
                          , bs::pack_< bd::uint16_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const
      {
        return _mm256_adds_epu16(a0,a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD( adds_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_< bd::uint8_<A0>, bs::avx_>
                          , bs::pack_< bd::uint8_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(A0 const& a0, A0 const& a1) const
      {
        return _mm256_adds_epu8(a0,a1);
      }
   };
} } }

#endif
