project(palindrome)

set(HEDEAR_FILES Palindrome.h)
set(SOURCE_FILES Palindrome.cpp Palindrome.cpp Palindrome.h)

add_library(libpalindrome STATIC ${SOURCE_FILES} main.cpp Palindrome.cpp Palindrome.h)
target_include_directories(libpalindrome PUBLIC .)

add_executable(palindrome ${SOURCE_FILES} main.cpp main.cpp Palindrome.cpp Palindrome.h)

target_link_libraries(palindrome libpalindrome)
