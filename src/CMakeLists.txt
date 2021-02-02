set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header ${header_path}/Student.h ${header_path}/Group.h ${header_path}/Deanary.h ${header_path}/Reader.h)
set(src Student.cpp Group.cpp Deanary.cpp Reader.cpp)


include_directories(${PROJECT_SOURCE_DIR} PUBLIC external/bprinter/include)
add_library(bprinter STATIC
        external/bprinter/include/bprinter/table_printer.h
        external/bprinter/include/bprinter/impl/table_printer.tpp.h
        external/bprinter/src/table_printer.cpp
        )


add_library(${PROJECT_NAME} SHARED
  ${header}
  ${src})
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
  pthread)

  
add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")

target_link_libraries(${PROJECT_NAME} bprinter)