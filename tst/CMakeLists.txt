include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR} 
   ${COM_SOURCE_DIR}/src
)

link_directories(
   ${COM_SOURCE_DIR}/tst/gtest
   ${COM_BINARY_DIR}/src
)

set(MOCKS 
   ${CMAKE_CURRENT_SOURCE_DIR}/mocks/can.c 
   ${CMAKE_CURRENT_SOURCE_DIR}/mocks/message.c
)

# link test targets
add_executable(testrun testcom.cc ${MOCKS})
target_link_libraries(testrun LIBCOM pthread gtest gtest_main)


