//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_NAN_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_NAN_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_nan_else capabilities

    If cond is @ref True returns @ref Allbits else returns f

    This is a convenient alias of @ref if_allbits_else
  **/
  const boost::dispatch::functor<tag::if_nan_else_> if_nan_else = {};
} }
#endif

#include <boost/simd/function/scalar/if_allbits_else.hpp>
#include <boost/simd/function/simd/if_nan_else.hpp>

#endif
