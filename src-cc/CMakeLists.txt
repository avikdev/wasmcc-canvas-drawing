cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# Set this according to yuor local emscripten installation dir.
set(EMS_BASEDIR "/Users/avikpaul/github/emsdk/upstream/emscripten")

set(CMAKE_TOOLCHAIN_FILE "${EMS_BASEDIR}/cmake/Modules/Platform/Emscripten.cmake")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

include_directories("${EMS_BASEDIR}/cache/sysroot/include")

project(starter-wasm VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../dist)
set(CMAKE_BUILD_TYPE_INIT "Release")

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(CMAKE_C_COMPILER "${EMS_BASEDIR}/emcc")
    set(CMAKE_CXX_COMPILER "${EMS_BASEDIR}/em++")
endif ()

add_executable(starter-wasm main.cc hello.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -s MODULARIZE=1 -s EXPORT_ES6=1 \
        -s EXPORT_NAME=\"WasmModule\"")

# Add linker flags for the target
target_link_options(starter-wasm PRIVATE "-O2")
target_link_options(starter-wasm PRIVATE "-s USE_SDL=2")
target_link_options(starter-wasm PRIVATE "-s WASM=1")
target_link_options(starter-wasm PRIVATE "-s MODULARIZE=1")
target_link_options(starter-wasm PRIVATE "-s EXPORT_ES6=1")
target_link_options(starter-wasm PRIVATE "-s EXPORT_NAME=WasmModule")
target_link_options(starter-wasm PRIVATE "-s EXPORTED_RUNTIME_METHODS=[ccall, cwrap, print]")
target_link_options(starter-wasm PRIVATE "-s EXPORTED_FUNCTIONS=[_main, _pingIt]")

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    #set_target_properties(starter-wasm PROPERTIES LINK_FLAGS "-o dist/engine.js -s USE_FREETYPE=1 -s DISABLE_EXCEPTION_CATCHING=0 -s DEMANGLE_SUPPORT=1 -s SAFE_HEAP=1 --bind -s WASM=1 -O2 -s LEGACY_GL_EMULATION=0  -s GL_UNSAFE_OPTS=0 --pre-js pre-module.js --post-js post-module.js -s ASSERTIONS=1 -s GL_ASSERTIONS=1 -s INVOKE_RUN=0  -std=c++11 -s USE_WEBGL2=1 -s FULL_ES3=1 -s USE_GLFW=3 -s OFFSCREENCANVAS_SUPPORT=1 --preload-file textures --preload-file shaders --preload-file fonts")
    set_target_properties(starter-wasm PROPERTIES LINK_FLAGS "-o foo.js")
endif ()