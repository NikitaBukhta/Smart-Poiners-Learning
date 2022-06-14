#------------------------------- STANDART CONFIGURATION -------------------------------#

cmake_minimum_required(VERSION 3.0.0)

project(test_unique_ptr)

set(
    CMAKE_CXX_STANDARD 17
)

set(
    CMAKE_CXX_STANDARD_REQUIRED 17
)

set(
    CMAKE_BUILD_TYPE
    debug
)

#----------------------------------- SET EXECUTABLE -----------------------------------#

set(
    EXE
    test_unique_ptr
)

set(
    SRC
    test_smart_pointers.cpp
)

add_executable(
    ${EXE}
    ${SRC}
)

#----------------------------------- LINK LIBRARIES ------------------------------------#

# --------------- Include Google Test ---------------#
include(FetchContent)
FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR} build)
endif()

set(
    ALL_LIBS
    test_class_lib
    # google test libs
    gtest_main
    gmock_main
)

target_link_libraries(
    ${EXE}
    ${ALL_LIBS}
)