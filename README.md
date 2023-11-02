# `#include <collections.h>`

> Easily swap out C++ collection classes

## What?

Nothing fancy.

Just a library which looks at your available `#include` paths and picks an unordered map or set to use.

## Installation

### xmake

#### `xmake.lua`

```lua
add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")
add_requires("collections")

target("Example")
    add_packages("collections")
    add_packages("unordered_dense") -- some library with cool collections
```

### vcpkg

#### `CMakeLists.txt`

```cmake
add_executable(Example main.cpp)

# Find string_format and link it to your target
find_package(string_format CONFIG REQUIRED)
target_link_libraries(Example PRIVATE collections::collections)

# If you're using C++20, you won't need fmt
target_compile_features(Example PRIVATE cxx_std_20)

# Else, add 'fmt' as a dependency
find_package(fmt CONFIG REQUIRED)
target_link_libraries(Example PRIVATE fmt::fmt)
```

#### `vcpkg.json`

```json
{
    "dependencies": ["mrowr-collections"]
}
```

And if you want to use `unordered-dense` or some other package:

```json
{
    "dependencies": ["mrowr-collections", "unordered-dense"]
}
```

#### `vcpkg-configuration.json`

```json
{
    "default-registry": {
        "kind": "git",
        "repository": "https://github.com/microsoft/vcpkg.git",
        "baseline": "354a05b99db8bec88347a8d35b46fbe7ef4c16da"
    },
    "registries": [
        {
            "kind": "git",
            "repository": "https://github.com/MrowrLib/Packages.git",
            "baseline": "9ee1e35202e5e551d8d1824d5b306c04166be3b5",
            "packages": ["mrowr-collections"]
        }
    ]
}
```

> _Update the default-registry baseline to the latest commit from https://github.com/microsoft/vcpkg_  
> _Update the MrowrLib/Packages baseline to the latest commit from https://github.com/MrowrLib/Packages_

## Why?

I want to be able to simply use a single definition of my unordered map and set types, and have them automatically use the best available library.

I don't want my libraries to require users to use a specific hashtable or set implementation.

With this, you can make a library and the user can choose what collection types they want to use.

## How?

```cpp
#include <collections.h>

int main() {
    // If you have unordered_dense available, this will be an ankerl::unordered_dense::map
    // If you have parallel_hashmap available, this will be a phmap::flat_hash_set
    // If you have robin hood available, this will be a robin_hood::unordered_map
    // If you have boost unordered available, this will be a boost::unordered_map
    // And so on...
    // Else it will fall back to std::unordered_map
    collections_map<int, int> map;

    // If you have unordered_dense available, this will be an ankerl::unordered_dense::set
    // If you have parallel_hashmap available, this will be a phmap::flat_hash_set
    // If you have robin hood available, this will be a robin_hood::unordered_set
    // If you have boost unordered available, this will be a boost::unordered_set
    // And so on...
    // Else it will fall back to std::unordered_set
    collections_set<int> set;
}
```

### Specifying a collection type

The following defines can be set which will force a specific collection type to be used:
- `COLLECTIONS_MAP_UNORDERED_DENSE`
- `COLLECTIONS_MAP_PHMAP`
- `COLLECTIONS_MAP_ROBIN_HOOD`
- `COLLECTIONS_MAP_BOOST`
- `COLLECTIONS_MAP_TSL`
- `COLLECTIONS_MAP_STD`
- `COLLECTIONS_SET_UNORDERED_DENSE`
- `COLLECTIONS_SET_PHMAP`
- `COLLECTIONS_SET_ROBIN_HOOD`
- `COLLECTIONS_SET_BOOST`
- `COLLECTIONS_SET_TSL`
- `COLLECTIONS_SET_STD`

> **Why these specific libraries?**
> Well, they just happen to be popular ones which I noticed.
> Happy to add others or change the order of their lookup.
> 
> Benchmarks for many of these libraries can be found here:
> [Comprehensive C++ Hashmap Benchmarks 2022](https://martin.ankerl.com/2022/08/27/hashmap-bench-01/)

### Or define the collection type yourself

If you want to use a collection type which isn't supported by this library, you can define your own collection type:

```cpp
#define collections_map my::awesome::unordered_map

// ^ make sure do do this BEFORE you include <collections.h>
#include <collections.h>
```

## License

Use however, no attribution required.

```
BSD Zero Clause License (SPDX: 0BSD)

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
```
