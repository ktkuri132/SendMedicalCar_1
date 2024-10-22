# 在外部创建库的方法


# 1.在当前目录下生成一个名为oled的库
add_library(oled OLED.c OLED_Data.c)

# 2.在当前库添加头文件路径
target_include_directories(oled PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# 3.在当前库链接pico_stdlib和硬件I2C库
target_link_libraries(oled pico_stdlib hardware_i2c)
target_link_libraries(oled i2c)

# 4.在当前库添加其他依赖库
target_include_directories(oled PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

# (非必要)5.忽略特定警告
set_source_files_properties(OLED_Data.c PROPERTIES COMPILE_FLAGS "-Wno-missing-braces")

