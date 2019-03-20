include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/syscalls)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DFUSE_USE_VERSION=26")
endif()

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -L${CMAKE_SOURCE_DIR}/../lib/bin")

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,--start-group")

add_executable(sofsmount
        sofsmount.cpp
)

target_link_libraries(sofsmount
        syscalls bin_syscalls
        direntries bin_direntries work_direntries
        fileblocks bin_fileblocks work_fileblocks
        freelists bin_freelists work_freelists
        dal bin_dal
        core
        rawdisk
        fuse
    )
