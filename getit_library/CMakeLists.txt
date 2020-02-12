find_package(Boost COMPONENTS program_options system REQUIRED )
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBXML++ REQUIRED libxml++-2.6)

# add lib source files
file(GLOB LIB_SOURSEC ${PROJECT_SOURCE_DIR}/getit_library/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/getit_library/src ${LIBXML++_INCLUDE_DIRS})

#add library
add_library(getit_library SHARED ${LIB_SOURSEC} )

#link 
target_link_libraries(getit_library ${Boost_LIBRARIES} ${LIBXML++_LIBRARIES} )
