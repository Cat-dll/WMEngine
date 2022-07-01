cmake_minimum_required(VERSION 3.10)

project(Game VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD_REQUIRED 11)
set(CMAKE_C_STANDARD 17)

if (MINGW)
    set(CMAKE_C_FLAGS_RELEASE "-O3 -m64")
    set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g -m64")
elseif (MSVC)
    set(CMAKE_C_FLAGS_RELEASE "/O2")
    set(CMAKE_C_FLAGS_DEBUG "/Zi /Wall")
endif()

add_executable(Game WIN32 "${CMAKE_SOURCE_DIR}/src/Game.c")
target_include_directories(Game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_directories(Game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/")

target_compile_definitions(Game PRIVATE BGFX_SHARED_LIB_USE)
target_compile_definitions(Game PRIVATE STB_IAMGE_IMPLEMENTATION)

target_link_libraries(Game PUBLIC "bgfx")

if (CMAKE_INSTALL)
    # Install game asset
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets/bin/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/assets")

    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
            PATTERN "*.dll")
endif()