//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLATTED_MAXIMUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLATTED_MAXIMUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes splatted_maximum value of its parameter.

  **/
  template<typename T> auto splatted_maximum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::splatted_maximum

      @see simd::splatted_maximum
    **/
    const boost::dispatch::functor<tag::splatted_maximum_> splatted_maximum = {};
  }
} }
#endif

#include <boost/simd/function/definition/splatted_maximum.hpp>
#include <boost/simd/arch/common/scalar/function/splatted_maximum.hpp>
//#include <boost/simd/arch/common/function/simd/splatted_maximum.hpp>

#endif