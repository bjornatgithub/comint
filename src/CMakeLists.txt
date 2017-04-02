add_executable(com main.c can.c message.c)

add_library(LIBCOM STATIC comint.c comcan.c)

target_link_libraries(com LIBCOM)

