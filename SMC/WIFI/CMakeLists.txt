add_library(wifi wifi.c)

target_include_directories(wifi PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(wifi PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(wifi PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(wifi pico_stdlib pico_cyw43_arch_lwip_threadsafe_background)