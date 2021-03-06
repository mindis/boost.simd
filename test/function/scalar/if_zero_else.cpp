//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/if_zero_else.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

#include <boost/simd/logical.hpp>
STF_CASE_TPL (" if_zero_else real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_zero_else;
  using bs::logical;

  // return type conformity test
  STF_EXPR_IS( if_zero_else(T(), T()), T);

  // specific values tests
  STF_EQUAL(if_zero_else(T(0), T(1)), T(1));
  STF_EQUAL(if_zero_else(T(1), T(1)), T(0));
  STF_EQUAL(if_zero_else(bs::Inf<T>(), T(1)) , T(0));
  STF_EQUAL(if_zero_else(bs::Minf<T>(), T(1)), T(0));
  STF_EQUAL(if_zero_else(bs::Nan<T>(), T(1)) , T(0));
  STF_EQUAL(if_zero_else(bs::Zero<T>(), T(1)), T(1));
 //  STF_EQUAL(if_zero_else(bs::True< bs::logical<T> >(), T(1)), T(0));


} // end of test for floating_

STF_CASE_TPL (" if_zero_else signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_zero_else;
  using bs::logical;

  // return type conformity test
   STF_EXPR_IS( if_zero_else(T(), T()), T);

  // specific values tests
  STF_EQUAL(if_zero_else(T(0), T(1)), T(1));
  STF_EQUAL(if_zero_else(T(1), T(1)), T(0));
} // end of test for signed_int_

