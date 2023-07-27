cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(SecondProject)

target_sources(app PRIVATE 
    src/main.c src/led_key_logic.c src/uart_logic.c
)
zephyr_include_directories(src)