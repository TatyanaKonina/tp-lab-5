cmake_minimum_required (VERSION 3.10.2)
project (tp-lab-5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")

include_directories(${PROJECT_SOURCE_DIR} PUBLIC external/bprinter/include)
add_library(bprinter STATIC
        external/bprinter/include/bprinter/table_printer.h
        external/bprinter/include/bprinter/impl/table_printer.tpp.h
        external/bprinter/src/table_printer.cpp
        )
target_link_libraries(Lab_5 bprinter)
include_directories(${PROJECT_NAME} PUBLIC external/json.hpp)


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(test)
