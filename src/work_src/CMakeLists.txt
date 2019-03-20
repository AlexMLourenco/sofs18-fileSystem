set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib/work)

include_directories(${CMAKE_SOURCE_DIR}/../include)

add_subdirectory(work_mksofs)
add_subdirectory(work_freelists)
add_subdirectory(work_fileblocks)
add_subdirectory(work_direntries)

