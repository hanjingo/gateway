cmake_minimum_required( VERSION 2.8 )
project( gateway )

set( CMAKE_BUILD_TYPE "Debug" )

include_directories( ${PROJECT_SOURCE_DIR} )
include_directories( ${PROJECT_SOURCE_DIR}/gateway/include )
include_directories( ${PROJECT_SOURCE_DIR}/lib/utils )

aux_source_directory(${PROJECT_SOURCE_DIR}/main MAIN)
aux_source_directory(${PROJECT_SOURCE_DIR}/gateway GATEWAY_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/lib/utils UTILS_SRCS)

add_executable( ${PROJECT_NAME} ${MAIN} ${GATEWAY_SRCS} ${UTILS_SRCS})