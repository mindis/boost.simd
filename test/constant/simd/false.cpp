//==================================================================================================
/*!

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/false.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check false behavior", STF_NUMERIC_TYPES )
{
  using boost::simd::as;
  using boost::simd::logical;
  using boost::simd::pack;
  using boost::simd::False;

  STF_TYPE_IS(decltype(False<pack<logical<T>>>()), pack<logical<T>> );

  pack<logical<T>> ref;
  for(auto e : ref) e = false;

  STF_ALL_EQUAL( False<pack<logical<T>>>(), ref);
}
