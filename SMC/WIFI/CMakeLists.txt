add_library(wifi wifi.c)

target_link_libraries(wifi pico_stdlib pico_cyw43_arch_lwip_threadsafe_background)
target_link_libraries(wifi pico_lwip pico_cyw43_arch pico_cyw43_driver)


target_include_directories(wifi PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(wifi PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

