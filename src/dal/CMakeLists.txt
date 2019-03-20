include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/rawdisk)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(dal STATIC
    dal_OC.cpp
    dal_SB.cpp
    dal_FILT.cpp
    dal_FBLT.cpp
    dal_DZ.cpp
    dal_IT.cpp
    dal_inode.cpp
)

