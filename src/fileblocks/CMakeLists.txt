include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/work_src/work_fileblocks)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(fileblocks STATIC
        alloc_fileblock.cpp
        free_fileblocks.cpp
        get_fileblock.cpp
        read_fileblock.cpp
        write_fileblock.cpp
)

