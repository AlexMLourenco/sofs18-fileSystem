include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/dal)
include_directories(${CMAKE_SOURCE_DIR}/freelists)
include_directories(${CMAKE_SOURCE_DIR}/fileblocks)
include_directories(${CMAKE_SOURCE_DIR}/direntries)

add_executable(testtool
        testtool.cpp
        testtool_msgs.cpp
        testtool_core.cpp
        testtool_freelists.cpp
        testtool_fileblocks.cpp
        testtool_direntries.cpp
        testtool_inodeattrs.cpp
)

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -L${CMAKE_SOURCE_DIR}/../lib/bin")

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,--start-group")

target_link_libraries(testtool
        direntries bin_direntries work_direntries
        fileblocks bin_fileblocks work_fileblocks
        freelists bin_freelists work_freelists
        dal bin_dal
        core
        rawdisk
    )
