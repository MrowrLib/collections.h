set_languages("c++20")

add_rules("mode.debug")

add_repositories("MrowrLib https://github.com/MrowrLib/Packages.git")

-- fmt is only required for the example
add_requires("unordered_dense", "parallel-hashmap", "robin-hood-hashing", "_Log_", "spdlog")

target("collections")
    set_kind("headeronly")
    add_headerfiles("include/(**.h)")
    add_includedirs("include", {public = true})

target("Example")
    set_kind("binary")
    add_files("Example.cpp")
    add_deps("collections")
    add_packages("unordered_dense", "parallel-hashmap", "robin-hood-hashing", "_Log_", "spdlog")
