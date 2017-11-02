cmake_minimum_required(VERSION 2.8)

project(a4)

# Silence warnings about deprecated GLUT functions
if(APPLE)
    add_definitions("-Wno-deprecated-declarations")
endif()

if(UNIX)
    # Enable C++11
    add_definitions("-std=c++11")
elseif(MSVC)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -WX")
  add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif()

find_package(Threads REQUIRED)

#vecmath include directory
include_directories(vecmath/include)
add_subdirectory(vecmath)
list (APPEND A3_LIBS vecmath)
list (APPEND A3_INCLUDES vecmath/include)
set (SRC_DIR "src/")

set(CPP_FILES
    ${SRC_DIR}processTouch.cpp
    ${SRC_DIR}getTouch.cpp
    ${SRC_DIR}main.cpp
    ${SRC_DIR}finger.cpp
    ${SRC_DIR}writeFile.cpp

    )

set(CPP_HEADERS
    ${SRC_DIR}processTouch.h
    ${SRC_DIR}getTouch.h
    ${SRC_DIR}finger.h
    ${SRC_DIR}writeFile.h
    )

add_executable(getTouch ${CPP_FILES} ${CPP_HEADERS} ${STB_SRC})
target_link_libraries (getTouch vecmath ${CMAKE_THREAD_LIBS_INIT})


