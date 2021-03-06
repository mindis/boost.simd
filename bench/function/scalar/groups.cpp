// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/function/scalar/group.hpp>
#include <boost/dispatch/meta/downgrade.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace nsb = ns::bench;

template <typename T>
struct groups_scalar
{
   template <typename U>
   void operator()(U min0, U max0, U min1, U max1)
   {
     using ret_type =   bs::pack<bd::downgrade_t<T>>;
     nsb::make_function_experiment_cpe_sized_<1>
       ( [](const T & x0, const T & x1) -> ret_type
       { return bs::saturated_(bs::group)(x0, x1); }
       , nsb::generators::rand<T>(min0, max0)
       , nsb::generators::rand<T>(min1, max1)
       );
   }
};


int main(int argc, char **argv) {
   nsb::parse_args(argc, argv);
   nsb::make_for_each<groups_scalar, double, std::int64_t, std::int32_t, std::int16_t>( -10,  10,  -10,  10);
   nsb::make_for_each<groups_scalar, std::uint64_t, std::uint32_t, std::uint16_t>(0,  10, 0,  10);
//    nsb::make_for_each<groups_scalar, NS_BENCH_SIGNED_NUMERIC_TYPES>( -10,  10,  -10,  10);
//    nsb::make_for_each<groups_scalar, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0,  10, 0,  10);
   return 0;
}

