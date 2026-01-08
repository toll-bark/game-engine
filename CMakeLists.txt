cmake_minimum_required(VERSION 3.28)
project(GameEngineDemo LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)
file(GLOB SOURCE_FILES "src/*.cpp")
file(GLOB TEST_FILES "test/*.cpp")

if (MSVC)
    # warning level 4
    add_compile_options(-O)
else()
    # additional warnings
    add_compile_options(-Wall -g)
endif()

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main main.cpp "${SOURCE_FILES}")
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tst "${TEST_FILES}" "${SOURCE_FILES}")
target_compile_features(tst PRIVATE cxx_std_17)
target_link_libraries(tst PRIVATE SFML::Graphics gtest gtest_main)