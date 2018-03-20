#set($NAME = ${StringUtils.removeAndHump($PROJECT_NAME_SEPARTED_WITH_SPACES," ")})
#set($PROJECT_LOWER = $NAME.toLowerCase())
#set($PROJECT_CAPTILIZED = $NAME)
#set($LIBRARY_NAME = "lib"+$PROJECT_LOWER)
#set($H_NAME = $PROJECT_CAPTILIZED+".h")
#set($CPP_NAME = $PROJECT_CAPTILIZED+".cpp")

project(modelnames)

set(HEDEAR_FILES ModelNames.h)
set(SOURCE_FILES ModelNames.cpp)

add_library(libmodelnames STATIC ${SOURCE_FILES})
target_include_directories(libmodelnames PUBLIC .)

add_executable(modelnames ${SOURCE_FILES} main.cpp)

target_link_libraries(modelnames libmodelnames)