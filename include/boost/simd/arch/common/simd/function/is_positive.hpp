//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_or.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#include <boost/simd/function/simd/is_gez.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(is_positive_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE  bs::bs::as_logical_t<A0> operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return is_gez(a0);
      }
   };

   BOOST_DISPATCH_OVERLOAD(is_positive_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE  bs::bs::as_logical_t<A0> operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return is_equal(bitwise_or(bitofsign(a0), One<A0>()), One<A0>());
      }
   };

} } }
#endif

