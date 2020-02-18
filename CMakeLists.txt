project(getit)
cmake_minimum_required(VERSION 3.5)

#message(${CMAKE_SYSTEM_PROCESSOR})

# set compile time options 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3 ")

# add configuration file
add_subdirectory(config)

# add doxygen dir
add_subdirectory(doc)

# add getit library
add_subdirectory(getit_library)

# add include dir for the exutables
include_directories ("${PROJECT_SOURCE_DIR}/getit_library/src")

# add runner src file
set(RUNNER_SRC ${PROJECT_SOURCE_DIR}/run_src/main.cpp)

# add target
add_executable(${PROJECT_NAME} ${RUNNER_SRC})
target_link_libraries(${PROJECT_NAME} getit_library )

