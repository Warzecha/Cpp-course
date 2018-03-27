#set($NAME = ${StringUtils.removeAndHump($PROJECT_NAME_SEPARTED_WITH_SPACES," ")})
#set($PROJECT_LOWER = $NAME.toLowerCase())
#set($PROJECT_CAPTILIZED = $NAME)
#set($LIBRARY_NAME = "lib"+$PROJECT_LOWER)
#set($H_NAME = $PROJECT_CAPTILIZED+".h")
#set($CPP_NAME = $PROJECT_CAPTILIZED+".cpp")

project(textpool)

set(HEDEAR_FILES TextPool.h)
set(SOURCE_FILES TextPool.cpp)

add_library(libtextpool STATIC ${SOURCE_FILES})
target_include_directories(libtextpool PUBLIC .)

add_executable(textpool ${SOURCE_FILES} main.cpp)

target_link_libraries(textpool libtextpool)