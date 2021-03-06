//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_ROL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_ROL_HPP_INCLUDED

#include <boost/simd/function/scalar/rol.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>
#include <boost/simd/arch/common/generic/function/rol.hpp>

#if defined(BOOST_HW_SIMD_X86)
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE_VERSION
#    include <boost/simd/arch/x86/sse1/simd/function/rol.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AMD_XOP_VERSION
#    include <boost/simd/arch/x86/xop/simd/function/rol.hpp>
#  endif
#endif

#if defined(BOOST_HW_SIMD_PPC)
#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
#    include <boost/simd/arch/ppc/vmx/simd/function/rol.hpp>
#  endif
#endif

#endif
