cmake_minimum_required(VERSION 2.8.9)

project(sofs18)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -D_FILE_OFFSET_BITS=64 -ggdb")
endif()

add_subdirectory(rawdisk)
add_subdirectory(core)

add_subdirectory(work_src)

add_subdirectory(mksofs)
add_subdirectory(dal)
add_subdirectory(freelists)
add_subdirectory(fileblocks)
add_subdirectory(direntries)
add_subdirectory(syscalls)

add_subdirectory(testtool)
add_subdirectory(sofsmount)

