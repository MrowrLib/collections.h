#pragma once

#if !defined(collections_map)
    #if defined(COLLECTIONS_MAP_UNORDERED_DENSE)
        #include <ankerl/unordered_dense.h>
        #define collections_map ankerl::unordered_dense::map
    #elif defined(COLLECTIONS_MAP_PHMAP)
        #include <parallel_hashmap/phmap.h>
        #define collections_map phmap::flat_hash_map
    #elif defined(COLLECTIONS_MAP_ROBIN_HOOD)
        #include <robin_hood.h>
        #define collections_map robin_hood::unordered_map
    #elif defined(COLLECTIONS_MAP_BOOST)
        #include <boost/unordered_map.hpp>
        #define collections_map boost::unordered_map
    #elif defined(COLLECTIONS_MAP_TSL)
        #include <tsl/robin_map.h>
        #define collections_map tsl::robin_map
    #elif defined(COLLECTIONS_MAP_STD)
        #include <unordered_map>
        #define collections_map std::unordered_map
    #endif
#endif

#if !defined(collections_map)
    #if __has_include(<ankerl/unordered_dense.h>)
        #include <ankerl/unordered_dense.h>
        #define collections_map ankerl::unordered_dense::map
    #elif __has_include(<parallel_hashmap/phmap.h>)
        #include <parallel_hashmap/phmap.h>
        #define collections_map phmap::flat_hash_map
    #elif __has_include(<robin_hood.h>)
        #include <robin_hood.h>
        #define collections_map robin_hood::unordered_map
    #elif __has_include(<boost/unordered_map.hpp>)
        #include <boost/unordered_map.hpp>
        #define collections_map boost::unordered_map
    #elif __has_include(<tsl/robin_map.h>)
        #include <tsl/robin_map.h>
        #define collections_map tsl::robin_map
    #elif __has_include(<unordered_map>)
        #include <unordered_map>
        #define collections_map std::unordered_map
    #else
        #error "No map library found"
    #endif
#endif

#if !defined(collections_set)
    #if defined(COLLECTIONS_SET_UNORDERED_DENSE)
        #include <ankerl/unordered_dense.h>
        #define collections_set ankerl::unordered_dense::set
    #elif defined(COLLECTIONS_SET_PHMAP)
        #include <parallel_hashmap/phmap.h>
        #define collections_set phmap::flat_hash_set
    #elif defined(COLLECTIONS_SET_ROBIN_HOOD)
        #include <robin_hood.h>
        #define collections_set robin_hood::unordered_set
    #elif defined(COLLECTIONS_SET_BOOST)
        #include <boost/unordered_set.hpp>
        #define collections_set boost::unordered_set
    #elif defined(COLLECTIONS_SET_TSL)
        #include <tsl/robin_set.h>
        #define collections_set tsl::robin_set
    #elif defined(COLLECTIONS_SET_STD)
        #include <unordered_set>
        #define collections_set std::unordered_set
    #endif
#endif

#if !defined(collections_set)
    #if __has_include(<ankerl/unordered_dense.h>)
        #include <ankerl/unordered_dense.h>
        #define collections_set ankerl::unordered_dense::set
    #elif __has_include(<parallel_hashmap/phmap.h>)
        #include <parallel_hashmap/phmap.h>
        #define collections_set phmap::flat_hash_set
    #elif __has_include(<robin_hood.h>)
        #include <robin_hood.h>
        #define collections_set robin_hood::unordered_set
    #elif __has_include(<boost/unordered_set.hpp>)
        #include <boost/unordered_set.hpp>
        #define collections_set boost::unordered_set
    #elif __has_include(<tsl/robin_set.h>)
        #include <tsl/robin_set.h>
        #define collections_set tsl::robin_set
    #elif __has_include(<unordered_set>)
        #include <unordered_set>
        #define collections_set std::unordered_set
    #else
        #error "No set library found"
    #endif
#endif
