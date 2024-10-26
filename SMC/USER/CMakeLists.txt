#声明可执行文件与参与编译的文件
add_executable(run main.c)

#添加链接库
target_link_libraries(run pico_stdlib pico_multicore hardware_uart)

target_include_directories(run PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(run PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(run i2c usart control pwm sys)

pico_enable_stdio_usb(run 1)
pico_enable_stdio_uart(run 1)

#添加输出文件
pico_add_extra_outputs(run)