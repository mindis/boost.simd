//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATAN2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATAN2_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/arch/common/detail/generic/invtrig.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>
#include <boost/simd/function/simd/is_gtz.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/negatenz.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/copysign.hpp>
#include <boost/simd/function/simd/is_inf.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#endif

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/simd/if_allbits_else.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#include <boost/simd/function/simd/logical_or.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( atan2_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
     inline A0 operator()(const A0& a0,const A0& a1) const
      {
        A0 a00 = a0, a10 = a1;
  #ifndef BOOST_SIMD_NO_INFINITIES
        auto test =  bs::logical_and(bs::is_inf(a0),  bs::is_inf(a1));
        a00 =  bs::if_else(test, bs::copysign(One<A0>(), a0), a0);
        a10 =  bs::if_else(test, bs::copysign(One<A0>(), a1), a1);
  #endif
        A0 z = detail::invtrig_base<A0,tag::radian_tag, tag::simd_type>::kernel_atan(a00/a10);
        //A0 z = atan(abs(a0/a1));  // case a1 > 0,  a0 > 0
        z = bs::negatenz(bs::if_else(bs::is_gtz(a10), z, bs::Pi<A0>()-z), a00);
        z =  bs::if_else( bs::is_eqz(a00),
                           bs::if_else_zero( bs::is_ltz(a10),  bs::Pi<A0>()),
                           z);
  #ifdef BOOST_SIMD_NO_NANS
        return z;
  #else
        return  bs::if_nan_else( bs::logical_or( bs::is_nan(a00),  bs::is_nan(a10)), z);
  #endif
      }
   };

} } }

#endif
