cmake_minimum_required(VERSION 3.4.1)

set(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(SAMPLE_LIBRARY_PATH ${ROOT_PATH}/../../../../samplendklibrary/build/intermediates/cmake/debug/obj/${ANDROID_ABI})

include_directories(${ROOT_PATH})

add_library(
        native-lib SHARED
        ${ROOT_PATH}/native-lib.cpp
        ${ROOT_PATH}/main/Main.cpp
)

add_library(sample-lib SHARED IMPORTED)
set_target_properties(
        sample-lib PROPERTIES IMPORTED_LOCATION
        ${SAMPLE_LIBRARY_PATH}/libsample-lib.so
)

find_library(
        log-lib
        log
)

target_link_libraries(
        native-lib
        sample-lib
        ${log-lib}
)