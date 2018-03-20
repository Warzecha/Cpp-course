#set($NAME = ${StringUtils.removeAndHump($PROJECT_NAME_SEPARTED_WITH_SPACES," ")})
#set($PROJECT_LOWER = $NAME.toLowerCase())
#set($PROJECT_CAPTILIZED = $NAME)
#set($LIBRARY_NAME = "lib"+$PROJECT_LOWER)
#set($H_NAME = $PROJECT_CAPTILIZED+".h")
#set($CPP_NAME = $PROJECT_CAPTILIZED+".cpp")

project(name)

set(HEDEAR_FILES Name.h)
set(SOURCE_FILES Name.cpp)

add_library(libname STATIC ${SOURCE_FILES})
target_include_directories(libname PUBLIC .)

add_executable(name ${SOURCE_FILES} main.cpp)

target_link_libraries(name libname)