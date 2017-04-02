cmake_minimum_required(VERSION 2.6)
project(COM)

#set(CMAKE_C_COMPILER ~/tools/gcc-arm-none-eabi-5_4-2016q3/bin/arm-none-eabi-gcc)
#set(CMAKE_CXX_COMPILER ~/tools/gcc-arm-none-eabi-5_4-2016q3/bin/arm-none-eabi-g++)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3")
set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(~/tools/gcc-arm-none-eabi-5_4-2016q3/arm-none-eabi/include/)

add_subdirectory(src)
add_subdirectory(tst)

