//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMMIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMMIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing cummin capabilities

    Computes the cumulate minimum of the vector elements

    @par Semantic:

    For every parameter of type T

    @code
    T r = cummin(x);
    @endcode

    is similar to:

    @code
    T r =x;
    for(int i=0;i < T::static_size; ++i)
      r[i] += min(r[i-1], r[i]);
    @endcode

  **/
  const boost::dispatch::functor<tag::cummin_> cummin = {};
} }
#endif

#include <boost/simd/function/scalar/cummin.hpp>
#include <boost/simd/function/simd/cummin.hpp>

#endif
