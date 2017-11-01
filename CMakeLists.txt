cmake_minimum_required(VERSION 3.8)
project(qt_generic_repl)
add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD 14)


## LIBRARY
set(LIBRARY_FILES
        src/repl/Repl.hpp

        src/repl/Repl.cpp
        src/repl/InputHandlerInterface.hpp src/repl/InputHandlerInterface.cpp)
add_library(qt_generic_repl_lib ${LIBRARY_FILES} src/repl/Repl.cpp src/repl/Repl.hpp)
target_include_directories(qt_generic_repl_lib
        PUBLIC src/include)


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
