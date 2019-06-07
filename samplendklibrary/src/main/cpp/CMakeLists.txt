cmake_minimum_required(VERSION 3.4.1)

set(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${ROOT_PATH})

add_library(
        sample-lib SHARED
        ${ROOT_PATH}/Sample.cpp
)

find_library(
        log-lib
        log
)

target_link_libraries(
        sample-lib
        ${log-lib}
)