cmake_minimum_required(VERSION 3.8)
project(qt_generic_repl)

add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_VERBOSE_MAKEFILE)
message(STATUS ${CMAKE_MODULE_PATH} " " ${CMAKE_PREFIX_PATH})
#set(CMAKE_PREFIX_PATH ${CMAKE_MODULE_PATH} /usr/local/Cellar/qt/5.9.2/lib/cmake/Qt5Widgets)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}
        /usr/local/Cellar/qt/5.9.2/lib/cmake
        )
message(STATUS ${CMAKE_MODULE_PATH} " " ${CMAKE_PREFIX_PATH})
find_package(Qt5Widgets REQUIRED)



set(CMAKE_AUTOMOC ON)



## LIBRARY
set(LIBRARY_FILES
        src/repl/Repl.hpp

        src/repl/Repl.cpp
        src/repl/InputHandlerInterface.hpp
        src/repl/InputHandlerInterface.cpp
        src/repl/ReplWindow.cpp
        src/repl/ReplWindow.hpp)
add_library(qt_generic_repl_lib ${LIBRARY_FILES})
target_include_directories(qt_generic_repl_lib
        PUBLIC src/include)
target_link_libraries(qt_generic_repl_lib Qt5::Widgets)

## TEST
set(GTEST_FILES
        test/main.cpp
        test/test_register_callback.cpp)
add_executable(qt_generic_repl_test ${GTEST_FILES})
target_link_libraries(qt_generic_repl_test gtest qt_generic_repl_lib)
target_include_directories(qt_generic_repl_test
        INTERFACE gtest
        PUBLIC test/include
        PUBLIC src/include)
add_test(${GTEST_FILES} qt_generic_repl_test)

## APP
set(APP_FILES
        src/app/main.cpp
        )
add_executable(qt_generic_repl ${APP_FILES})
target_link_libraries(qt_generic_repl qt_generic_repl_lib)
