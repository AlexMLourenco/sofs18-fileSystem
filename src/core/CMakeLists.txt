include_directories(${CMAKE_SOURCE_DIR}/rawdisk)

add_library(core STATIC 
    exception.cpp
    probing.cpp
    bin_selection.cpp
    blockviews.cpp
)

add_executable(showsizes showsizes.cpp)
target_link_libraries(showsizes rawdisk core)

add_executable(showblock showblock.cpp)
target_link_libraries(showblock rawdisk core)
