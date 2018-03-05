project(multiplicationtable)

set(HEDEAR_FILES MultiplicationTable.h)
set(SOURCE_FILES MultiplicationTable.cpp MultiplicationTable.cpp MultiplicationTable.h main.cpp)

add_library(libmultiplicationtable STATIC ${SOURCE_FILES} main.cpp MultiplicationTable.cpp MultiplicationTable.h main.cpp MultiplicationTable.cpp MultiplicationTable.h)
target_include_directories(libmultiplicationtable PUBLIC .)

add_executable(multiplicationtable ${SOURCE_FILES} main.cpp main.cpp MultiplicationTable.cpp MultiplicationTable.h main.cpp MultiplicationTable.cpp MultiplicationTable.h)

target_link_libraries(multiplicationtable libmultiplicationtable)
