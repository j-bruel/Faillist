##
## Cmake minimun version
##
cmake_minimum_required(VERSION 3.10)

##
## Projet Name
##
project(faillist C)

##
## C Stantard compilation
##
set(CMAKE_C_STANDARD 11)

##
## Binary / Library location
##
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

##
## Flags
##
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG} -g3 -W -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra")

##
## Headers included
##
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/jsmn/include)

##
## Sources files
##
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

##
## Create binary / Link
##
add_executable(${PROJECT_NAME}          ${SOURCE_FILES}
                                        ${INCLUDE_FILES})

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/jsmn/libjsmn.a)
