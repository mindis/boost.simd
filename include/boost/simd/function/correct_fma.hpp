//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic
    Function object function implementing correct_fma capabilities

    Computes fused multiply/add of its parameter.

    @par semantic:
    For any given value @c x, @c y, @c z of type @c T:

    @code
    T r = correct_fma(x, y, z);
    @endcode

    is similar to:

    @code
    T r = x*y+z;
    @endcode

    but with only one rounding

    @par Note:

    - For integer x*y+z is performed

    - For floating points numbers, always computes the correct fused multiply add,
    this means the computation of x*y+z with only one rounding operation.
    On machines not possessing this hard wired capability this can be very
    expansive.

    - @c correct_fma is in fact a transitory function that allows to ensure
    strict @ref fma capabilities,  i.e. only one rounding operation and no undue
    overflow in intermediate computations.

    - If you are using this function for a system with no hard wired @ref fma
    and are sure that overflow is not a problem
    you can define BOOST_SIMD_DONT_CARE_CORRECT_FMA_OVERFLOW to get better
    performances.

    correct_fma is never used internally in boost.simd.

    @par Decorators

    std_ for floating entries

    @see  fma
**/
     const boost::dispatch::functor<tag::correct_fma_> correct_fma = {};
} }
#endif

#include <boost/simd/function/scalar/correct_fma.hpp>
#include <boost/simd/function/simd/correct_fma.hpp>

#endif
