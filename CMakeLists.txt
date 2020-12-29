cmake_minimum_required( VERSION 2.8 )
set( CMAKE_BUILD_TYPE "Debug" )

PROJECT( ipfs_gateway )

INCLUDE_DIRECTORIES(
    include
)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

ADD_EXECUTABLE( ${PROJECT_NAME} ${DIR_SRCS})
