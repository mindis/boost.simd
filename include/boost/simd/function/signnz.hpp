//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNNZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNNZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing signnz capabilities

    Returns the sign of x. I.e. -1 or 1, according
    x is negative or positive.

    This function never returns @ref Zero (zero is considered positive for integers).

    For floating point numbers the bit of sign is taken into account and so
    we always have signnz(-z) == -signnz(z)).

    The result for @ref Nan entry is undefined

    @par Semantic:

    @code
    T r = signnz(x);
    @endcode

    is similar to:

    @code
    T r = is_nan(x) ? Nan<T>() : (is_negative(x) ? T(-1) : T(1));
    @endcode

    @see Mzero,  sign, is_negative, is_positive

  **/
  const boost::dispatch::functor<tag::signnz_> signnz = {};
} }
#endif

#include <boost/simd/function/scalar/signnz.hpp>
#include <boost/simd/function/simd/signnz.hpp>

#endif
