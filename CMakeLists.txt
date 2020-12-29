cmake_minimum_required( VERSION 2.8 )
set( CMAKE_BUILD_TYPE "Debug" )

project( gate )

include_directories(
    include
)

aux_source_directory(src DIR_SRCS)

add_executable( ${PROJECT_NAME} ${DIR_SRCS})
