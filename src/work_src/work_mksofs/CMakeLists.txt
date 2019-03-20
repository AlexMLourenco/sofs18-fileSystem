include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/rawdisk)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_library(work_mksofs STATIC
    work_mksofs_CS.cpp
    work_mksofs_SB.cpp
    work_mksofs_FILT.cpp
    work_mksofs_IT.cpp
    work_mksofs_FBLT.cpp
    work_mksofs_RD.cpp
    work_mksofs_RC.cpp
)

