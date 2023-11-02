// Define the collections_set yourself!
// #include <parallel_hashmap/phmap.h>
// #define collections_map phmap::flat_hash_map

// #define COLLECTIONS_MAP_PHMAP
// #define COLLECTIONS_MAP_ROBIN_HOOD
// #define COLLECTIONS_MAP_STD

// #define COLLECTIONS_SET_PHMAP
// #define COLLECTIONS_SET_ROBIN_HOOD
// #define COLLECTIONS_SET_STD

#include <_Log_.h>
#include <collections.h>

int main() {
    collections_map<int, int> map;
    _Log_("Map type: {}", typeid(map).name());

    collections_set<int> set;
    _Log_("Set type: {}", typeid(set).name());

    return 0;
}