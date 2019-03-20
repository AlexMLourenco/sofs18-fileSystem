include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/dal)
include_directories(${CMAKE_SOURCE_DIR}/freelists)
include_directories(${CMAKE_SOURCE_DIR}/fileblocks)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(work_fileblocks STATIC
        work_alloc_fileblock.cpp
        work_free_fileblocks.cpp
        work_get_fileblock.cpp
        work_read_fileblock.cpp
        work_write_fileblock.cpp
)

