//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/acoth.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" acoth",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::acoth;
  using r_t = decltype(acoth(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(acoth(bs::Inf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(acoth(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(acoth(bs::Mone<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(acoth(bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(acoth(bs::One<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(acoth(bs::Zero<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(acoth(bs::Two<T>()), T(0.549306144334054845697622618461), 0.5);
}
