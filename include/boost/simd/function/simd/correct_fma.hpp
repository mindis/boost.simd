//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_CORRECT_FMA_HPP_INCLUDED

#include <boost/simd/function/scalar/correct_fma.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>
#include <boost/simd/arch/common/simd/function/correct_fma.hpp>

#if defined(BOOST_HW_SIMD_X86)
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_FMA3_VERSION
#    include <boost/simd/arch/x86/fma3/simd/function/correct_fma.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_FMA4_VERSION
#    include <boost/simd/arch/x86/fma4/simd/function/correct_fma.hpp>
#  endif
#endif

#if defined(BOOST_HW_SIMD_PPC)
#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
#    include <boost/simd/arch/ppc/vmx/simd/function/correct_fma.hpp>
#  endif
#endif

#endif
