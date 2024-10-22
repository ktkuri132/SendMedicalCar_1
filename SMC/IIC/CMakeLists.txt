#确定目标和源文件
#add_executable(i2c i2c.c i2clib.c)
#创建静态库
add_library(i2c i2clib.c)
# 添加外部链接库
target_link_libraries(i2c pico_stdlib hardware_i2c)

#添加本目录头文件
target_include_directories(i2c PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(i2c PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

# 启用 USB 串口支持
pico_enable_stdio_usb(i2c 1)
pico_enable_stdio_uart(i2c 0)

#pico_add_extra_outputs(i2c)

# 添加外部库的方法

# 1.添加子目录
add_subdirectory(OLED)
add_subdirectory(MPU6050)

# 2.链接子目录生成的库
target_link_libraries(i2c oled)
#target_link_libraries(i2c mpu6050)