CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/config/config.xml ${CMAKE_BINARY_DIR}/config/config.xml)
file(GLOB CSV_FILES ${CMAKE_SOURCE_DIR}/config/customers/*.csv )
file(COPY ${CSV_FILES} DESTINATION ${CMAKE_BINARY_DIR}/config/customers)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/config/managers)

