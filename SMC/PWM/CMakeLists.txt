add_library(pwm pwm.c)

target_include_directories(pwm PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(pwm PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(pwm pico_stdlib hardware_pwm)
target_link_libraries(pwm sys)