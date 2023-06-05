
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
  files{"lib/lua/**.h", "lib/lua/**.c"}
  removefiles{"lib/lua/testes/**"}

project "shared"
  kind "StaticLib"
  language("C++")
  cppdialect "C++20"
  targetdir "bin/%{cfg.buildcfg}"

  files{"src/**.hpp", "src/**.cpp"}
  removefiles{"src/main.cpp"}
  includedirs { 
    "src",
    "lib"
  }
  libdirs {"lib"}
  links {"tinyPTC", "picoPNG", "X11", "lua5"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"
    buildoptions {"-Wall -Wpedantic -Wextra -Wconversion"}

  filter "configurations:Release"
    defines { "RELEASE" }
    optimize "On"


project "game"
  kind "ConsoleApp"
  language("C++")
  cppdialect "C++20"
  targetdir "bin/%{cfg.buildcfg}"

  files{"src/main.cpp"}

  includedirs { 
    "src",
    "lib"
  }
  libdirs {"lib"}
  links {"shared", "tinyPTC", "picoPNG", "X11", "lua5"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"
    buildoptions {"-Wall -Wpedantic -Wextra -Wconversion"}

  filter "configurations:Release"
    defines { "RELEASE" }
    optimize "On"


project "test"
  kind "ConsoleApp"
  language("C++")
  targetdir "bin/%{cfg.buildcfg}"
  cppdialect "C++20"

  files{"test/**.h", "test/**.cpp"}

  includedirs {
    "src",
    "lib"
  }
  libdirs {"lib"}
  links {"shared", "tinyPTC", "picoPNG", "X11", "lua5"}

  postbuildcommands {
    "bin/%{cfg.buildcfg}/test"
  }

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"
    buildoptions {"-Wall -Wpedantic -Wextra -Wconversion"}

  filter "configurations:Release"
    defines { "RELEASE" }
    optimize "On"

project "clean_shared"
  kind "Makefile"
  targetname "clean_shared"
  buildcommands {
      "@${MAKE} --no-print-directory -C . -f shared.make clean"
  }

