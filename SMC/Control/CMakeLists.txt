add_library(control control.c control_task.c)

target_include_directories(control PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(control PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(control pico_stdlib)
target_link_libraries(control i2c usart pwm sys)

pico_enable_stdio_usb(control 1)
pico_enable_stdio_uart(control 0)