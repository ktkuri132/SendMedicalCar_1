# 在外部创建库的方法

# 1.在当前目录下生成一个名为mpu6050的库
add_library(mpu6050 inv_mpu.c inv_mpu_dmp_motion_driver.c mpu6050.c)

# 2.在当前库添加头文件路径
target_include_directories(mpu6050 PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# 3.在当前库链接pico_stdlib和硬件I2C库
target_link_libraries(mpu6050 pico_stdlib hardware_i2c)

# 4.在当前库添加父目录的头文件路径
target_include_directories(mpu6050 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)


