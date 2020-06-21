cmake_minimum_required(VERSION 3.17)
project(GEN_RefactorC)

set(CMAKE_CXX_STANDARD 14)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

include_directories(.)

add_executable(GEN_RefactorC
        Customer.cpp
        Customer.h
        main.cpp
        Movie.h
        MovieState.h
        MovieStateChildren.h
        MovieStateRegular.h
        MovieStateNewRelease.h
        Rental.h)

# Trivial example using gtest and gmock
add_executable(test_lab
        tests/CustomerTest.cpp
        Customer.cpp
        Customer.h
        Rental.h
        tests/MovieTest.cpp
        tests/RentalTest.cpp)
target_link_libraries(test_lab gtest gmock_main)
add_test(NAME test_lab COMMAND test_lab)

