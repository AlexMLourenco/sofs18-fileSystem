include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/work_src/work_freelists)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(freelists STATIC
    alloc_block.cpp
    free_block.cpp
    replenish_brcache.cpp
    deplete_bicache.cpp
    alloc_inode.cpp
    free_inode.cpp
    replenish_ircache.cpp
    deplete_iicache.cpp
)

