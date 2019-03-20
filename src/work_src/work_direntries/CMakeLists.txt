include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/dal)
include_directories(${CMAKE_SOURCE_DIR}/freelists)
include_directories(${CMAKE_SOURCE_DIR}/fileblocks)
include_directories(${CMAKE_SOURCE_DIR}/direntries)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(work_direntries STATIC
        work_check_dir_empty.cpp
        work_get_direntry.cpp
        work_delete_direntry.cpp
        work_rename_direntry.cpp
        work_add_direntry.cpp
        work_traverse_path.cpp
)

