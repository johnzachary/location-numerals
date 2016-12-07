cmake_minimum_required(VERSION 3.0)
set(RELEASE_DATE 2016-12-05)
project(locnum)
enable_testing()

find_package(PkgConfig)
add_definitions(-Wall -Werror -std=c++11)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


## Build the static library

set(LIBLOCNUM_SRC
    src/LocationNumerals.cpp
)
add_library(liblocnum STATIC ${LIBLOCNUM_SRC})
set_target_properties(liblocnum PROPERTIES
    OUTPUT_NAME locnum 
    VERSION 0.1.0
)


## Build the application

set(LOCNUM_SRC
    src/main.cpp
)
add_executable(locnum ${LOCNUM_SRC})
target_link_libraries(locnum liblocnum)
install(TARGETS locnum RUNTIME DESTINATION bin)

