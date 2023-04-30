add_rules("mode.debug", "mode.release")

set_xmakever("2.7.4")
add_rules("plugin.compile_commands.autoupdate")

add_repositories("local-repo repo")

option("message")
    set_default(false)
    add_defines("VERBOSE_MESSAGE")
option_end()

set_languages("cxx17")

set_warnings("all", "error")

if is_plat("windows") then
    add_defines("NOMINMAX")
end

add_requireconfs("*", {build = true})

add_requires("fmt")

add_requires("argparse")

target("app")
    set_kind("binary")
    add_files("src/*.cpp")
    add_options("message")
    add_packages("fmt", "argparse")
