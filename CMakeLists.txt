#在项目根目录下创建CMakeLists.txt文件，以便于编译器编译整个项目

#cmake最小版本
cmake_minimum_required(VERSION 3.12)

#包含pico的sdk的cmake库,用于链接其他cmake文件
include(pico_sdk_import.cmake)
include(pico_extras_import_optional.cmake)
include(example_auto_set_url.cmake)

#项目名称
project(SendMedicalCar C CXX ASM)

#设置本项目文件总配置路径
set(SendMedicalCar_PATH ${PROJECT_SOURCE_DIR})

#设置C/C++标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#检查SDK版本
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# 初始化SDK（调用在SDK中的cmake函数）
pico_sdk_init()

#设置编译器选项
add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()

#设置项目路径(被添加的文件夹中必须要有CMakeLists.txt文件)
add_subdirectory(SMC/USER)
add_subdirectory(SMC/IIC)
add_subdirectory(SMC/USART)
add_subdirectory(SMC/Control)
add_subdirectory(SMC/PWM)