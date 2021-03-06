//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_SIMD_TRIG_BASE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_SIMD_TRIG_BASE_HPP_INCLUDED

#include <boost/simd/arch/common/detail/simd/trig_reduction.hpp>
#include <boost/simd/function/simd/any.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/is_invalid.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/is_flint.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/function/simd/shr.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/if_allbits_else.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/oneminus.hpp>
#include <boost/simd/constant/maxleftshift.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bd =  boost::dispatch;
    namespace bs =  boost::simd;

    template < class A0, class unit_tag, class mode>
    struct trig_base < A0, unit_tag,  tag::simd_type, mode>
    {
      typedef typename bs::as_logical_t<A0>                        bA0; // logical type associated to A0
      typedef trig_reduction<A0,unit_tag, tag::simd_type, mode> redu_t;
      typedef trig_evaluation<A0,tag::simd_type>                eval_t;
      typedef typename bd::scalar_of<A0>::type                     sA0; // scalar version of A0
      typedef typename bd::as_integer<A0, signed>::type       int_type; // signed integer type associated to A0
      typedef typename bs::as_logical<int_type>::type        bint_type; // logical type associated to int_type
      typedef typename bd::scalar_of<int_type>::type         sint_type; // scalar version of the associated type
      typedef typename mode::type                                style;

      // for all functions the scalar algorithm is:
      // * range reduction
      // * computation of sign and evaluation selections flags
      // * evaluations of the two branches and selection using flags
      // * return with flag based corrections and inf and nan or specific invalid cases inputs considerations

      static inline A0 cosa(const A0 a0){ return cosa(a0, style()); }
      static inline A0 sina(const A0 a0){ return sina(a0, style()); }
      static inline A0 tana(const A0 a0){ return tana(a0, style()); }
      static inline A0 cota(const A0 a0){ return cota(a0, style()); }
      static inline std::pair<A0,A0> sincosa(const A0 a0){ return sincosa(a0,style()); }

    private:
      static inline A0 cosa(const A0 a0, const tag::fast&)
      {
        const A0 x =  scale(a0);
        return  eval_t::cos_eval(sqr(x));
      }

      static inline A0 cosa(const A0 a0, const tag::regular&)
      {
        const A0 x = bs::abs(a0);
        A0 xr = Nan<A0>();
        const int_type n =  redu_t::reduce(x, xr);
        const int_type swap_bit = n&One<int_type>();
        const int_type sign_bit = shift_left(bitwise_xor(swap_bit, shr(n&Two<int_type>(), 1)), Maxleftshift<sint_type>());
        const A0 z = sqr(xr);
        const A0 se = eval_t::sin_eval(z, xr);
        const A0 ce = eval_t::cos_eval(z);
        return  bitwise_xor(if_else(is_nez(swap_bit), se, ce), sign_bit);
      }

      static inline A0 sina(const A0 a0_n, const tag::fast&)
      {
        const A0 x =   scale(a0_n);
        const A0 se = eval_t::sin_eval(sqr(x), x);
        return se;
      }

      static inline A0 sina(const A0 a0_n, const tag::regular&)
      {
        const A0 a0 = a0_n;
        const A0 x = bs::abs(a0);
        A0 xr = Nan<A0>();
        const int_type n = redu_t::reduce(x, xr);
        const int_type swap_bit = n&One<int_type>();
        const A0 sign_bit = bitwise_xor(bitofsign(a0),
                                        shift_left(n&Two<int_type>(),Maxleftshift<sint_type>()-1));
        const A0 z = sqr(xr);
        const A0 se = eval_t::sin_eval(z, xr);
        const A0 ce = eval_t::cos_eval(z);
        return bitwise_xor(if_else(is_eqz(swap_bit),se, ce), sign_bit);
      }

      static inline A0 tana(const A0 a0_n, const tag::fast&)
      {
        const A0 bte = eval_t::base_tancot_eval(scale(a0_n));
        return bte;
      }

      static inline A0 tana(const A0 a0_n, const tag::regular&)
      {
        const A0 a0 = a0_n;
        const A0 x =  bs::abs(a0);
        A0 xr = Nan<A0>();
        const int_type n = redu_t::reduce(x, xr);
        const A0 y = eval_t::tan_eval(xr, oneminus(shift_left((n&One<int_type>()), 1)));
        // 1 -- n even  -1 -- n odd
        const bA0 testnan = redu_t::tan_invalid(a0);
        return if_allbits_else(testnan, bitwise_xor(y, bitofsign(a0)));
      }

      static inline A0 cota(const A0 a0_n, const tag::fast&)
      {
        const A0 bte = eval_t::base_tancot_eval(scale(a0_n));
        return rec(bte);
      }
      static inline A0 cota(const A0& a0, const tag::regular&)
      {
        const A0 x = bs::abs(a0);
        A0 xr = Nan<A0>();
        const int_type n = redu_t::reduce(x, xr);
        const A0 y = eval_t::cot_eval(xr, oneminus(shift_left((n&One<int_type>()), 1)));
        // 1 -- n even -1 -- n odd
        const bA0 testnan = redu_t::cot_invalid(a0);
        // this if_else is normally not needed but with clang the zero value if eroneous
        // if not there !
        return if_else(is_nez(a0), if_allbits_else(testnan
                                                  , bitwise_xor(y, bitofsign(a0))), rec(a0));
      }

      // simultaneous cosa and sina function
      static inline std::pair<A0, A0> sincosa(const A0& a0, const tag::fast&)
      {
        A0 x =  scale(a0);
        A0 z =  sqr(x);
        return {eval_t::sin_eval(z, x), eval_t::cos_eval(z)};
      }

      static inline  std::pair<A0, A0> sincosa(const A0& a0, const tag::regular&)
      {
        const A0 x =  bs::abs(a0);
        A0 xr = Nan<A0>();
        const int_type n = redu_t::reduce(x, xr);
        const int_type swap_bit = n&One<int_type>();
        const A0 z = bs::sqr(xr);
        const int_type cos_sign_bit = shift_left(bitwise_xor(swap_bit
                                                            , shr(n&Two<int_type>(), 1))
                                                ,  Maxleftshift<sint_type>());
        const int_type sin_sign_bit = bitwise_xor(shift_left(n&Two<int_type>()
                                                            , Maxleftshift<sint_type>()-1)
                                                 , bitofsign(a0));
        const A0 t1 = eval_t::sin_eval(z, xr);
        const A0 t2 = eval_t::cos_eval(z);
        const bint_type test = is_nez(swap_bit);
        return { bitwise_xor(if_else(test, t2, t1),sin_sign_bit)
               , bitwise_xor(if_else(test, t1, t2),cos_sign_bit) };
      }

      static inline A0 scale(const A0& a0)
      {
        return if_allbits_else(is_greater(bs::abs(a0),
                              trig_ranges<A0,unit_tag>::max_range()), a0)
          *trig_ranges<A0,unit_tag>::scale();
      }

    };
  }
} }


#endif
