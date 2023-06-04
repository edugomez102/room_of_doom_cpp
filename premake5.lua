
workspace "room_of_doom"
  configurations { "Debug", "Release"}

project "tinyPTC"
  kind "StaticLib"
  language("C")
  files{"lib/tinyPTC/**.h", "lib/tinyPTC/**.c"}

project "picoPNG"
  kind "StaticLib"
  language("C++")
  files{"lib/picoPNG/**.h", "lib/picoPNG/**.cpp"}

project "lua5"
  kind "StaticLib"
  language("C")
  files{"lib/lua-5.4.6/**.h", "lib/lua-5.4.6/**.c"}

project "game"
  kind "ConsoleApp"
  language("C++")
  cppdialect "C++20"
  targetdir "bin/%{cfg.buildcfg}"

  files{"src/**.hpp", "src/**.cpp"}
  includedirs { 
    "src",
    "lib"
  }
  libdirs {"lib"}
  links {"tinyPTC", "picoPNG", "X11", "lua5"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"


project "test"
  kind "ConsoleApp"
  language("C++")
  targetdir "bin/%{cfg.buildcfg}"
  cppdialect "C++20"

  files{"test/**.h", "test/**.cpp"}
  files{"src/**.hpp", "src/**.cpp"}
  removefiles{"src/main.cpp"}

  includedirs {
    "src",
    "lib"
  }
  links {"tinyPTC", "picoPNG", "X11", "lua5"}


