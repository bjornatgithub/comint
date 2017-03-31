cmake_minimum_required(VERSION 2.6)
project(COM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(src)
add_subdirectory(tst)

include_directories(${COM_SOURCE_DIR}/src ${COM_SOURCE_DIR}/tst)
link_directories(${COM_SOURCE_DIR}/tst/gtest)

# link test targets
add_executable(testrun ${COM_SOURCE_DIR}/tst/testcom.cc)
target_link_libraries(testrun LIBCOM MOCK pthread gtest gtest_main)

