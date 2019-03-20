include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/dal)
include_directories(${CMAKE_SOURCE_DIR}/freelists)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(work_freelists STATIC
    work_alloc_block.cpp
    work_free_block.cpp
    work_replenish_brcache.cpp
    work_deplete_bicache.cpp
    work_alloc_inode.cpp
    work_free_inode.cpp
    work_replenish_ircache.cpp
    work_deplete_iicache.cpp
)

