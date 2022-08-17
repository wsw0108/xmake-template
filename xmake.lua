add_rules("mode.debug", "mode.release")

add_repositories("local-repo repo")

set_languages("cxx17")

set_warnings("all", "warning")

if is_plat("windows") then
    add_defines("NOMINMAX")
end

add_requireconfs("*", {build = true})

add_requires("fmt")

add_requires("gflags")

target("app")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("fmt", "gflags")
