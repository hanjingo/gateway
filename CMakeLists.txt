cmake_minimum_required( VERSION 2.8 )
project( gateway )

set( CMAKE_BUILD_TYPE "Debug" )

include_directories( include )
include_directories( ${PROJECT_SOURCE_DIR} )

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/lib/utils UTILS_SRCS)

add_executable( ${PROJECT_NAME} ${DIR_SRCS} ${UTILS_SRCS})