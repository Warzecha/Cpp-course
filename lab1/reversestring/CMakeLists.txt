project(reversestring)

set(HEDEAR_FILES ReverseString.h)
set(SOURCE_FILES ReverseString.cpp)
set(SOURCE_FILES main.cpp ReverseString.cpp ReverseString.h)

add_library(libreversestring STATIC ${SOURCE_FILES})
target_include_directories(libreversestring PUBLIC .)

add_executable(reversestring ${SOURCE_FILES} main.cpp )


target_link_libraries(reversestring libreversestring)
