add_library(usart usart.c)

target_include_directories(usart PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(usart PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(usart pico_stdlib hardware_uart)

