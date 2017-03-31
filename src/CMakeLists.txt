add_executable(com main.c message.c)

add_library(LIBCOMDRV can.c)
add_library(LIBCOM comint.c comcan.c)

target_link_libraries(com LIBCOM LIBCOMDRV)

