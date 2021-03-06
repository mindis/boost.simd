//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-swar
    Function object implementing deinterleave_second capabilities

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of type T:

    @code
    T0 r = deinterleave_second(x,y);
    @endcode

    is equivalent to :

    @code
    r = [ x[n/2] x[n/2+1] ... x[n-1] y[n/2] y[n/2+1] ... y[n-1] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>

  **/
  const boost::dispatch::functor<tag::deinterleave_second_> deinterleave_second = {};
#endif
} }

#include <boost/simd/function/simd/deinterleave_second.hpp>

#endif
