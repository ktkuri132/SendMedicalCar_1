add_library(sys sys.c)

target_include_directories(sys PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(sys PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(sys pico_stdlib)
target_link_libraries(sys i2c usart control pwm)

