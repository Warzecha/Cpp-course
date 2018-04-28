
project(comparable)

set(HEDEAR_FILES Comparable.h)
set(SOURCE_FILES Comparable.cpp)

add_library(libcomparable STATIC ${SOURCE_FILES})
target_include_directories(libcomparable PUBLIC .)



target_link_libraries(libcomparable libstudentrepository)