include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/rawdisk)
include_directories(${CMAKE_SOURCE_DIR}/work_src/work_mksofs)
include_directories(${CMAKE_SOURCE_DIR}/../include)

add_executable(mksofs 
    mksofs_main.cpp
    mksofs_CS.cpp
    mksofs_SB.cpp
    mksofs_FILT.cpp
    mksofs_IT.cpp
    mksofs_FBLT.cpp
    mksofs_RD.cpp
    mksofs_RC.cpp
)

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -L${CMAKE_SOURCE_DIR}/../lib/bin")

target_link_libraries(mksofs core rawdisk bin_mksofs work_mksofs)

