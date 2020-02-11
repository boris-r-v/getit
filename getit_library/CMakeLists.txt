# need library
find_package(Boost COMPONENTS program_options system REQUIRED )
#find_package (Threads)

# add lib source files
file(GLOB LIB_SOURSEC ${PROJECT_SOURCE_DIR}/getit_library/src/*.cpp)
#file(GLOB LIB_HEADER ${PROJECT_SOURCE_DIR}/getit_library/src/*.h)
include_directories("${PROJECT_SOURCE_DIR}/getit_library/src")

add_library(getit_library SHARED ${LIB_SOURSEC} )

#link 
#target_link_libraries(getit_library ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(getit_library ${Boost_LIBRARIES} )
