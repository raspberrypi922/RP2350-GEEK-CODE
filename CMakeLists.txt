# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

#   cd build
#   cmake -G Ninja ..
#   ninja

#boards include file has pin defines and flash memory size
#/home/bucky/dev/pico/pico-sdk/src/boards/include/boards/waveshare_rp2350_geek.h

set(PICO_BOARD waveshare_rp2350_geek CACHE STRING "Board type")

string(APPEND CMAKE_EXE_LINKER_FLAGS "-Wl,--print-memory-usage")

cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(rp2350geek)
pico_sdk_init()


# executable name and dependants
add_executable(rp2350geek 
    main.c
    c/Splash.c
    c/Splash.h
    lib/Config/DEV_Config.c
    lib/Config/DEV_Config.h
    lib/GUI/GUI_Paint.c
    lib/GUI/GUI_Paint.h
    lib/Images/Rp2350Geek.c
    lib/Images/Rp2350Geek.h
    lib/LCD/LCD_1in14_V2.c
    lib/LCD/LCD_1in14_V2.h
)

#name and version
pico_set_program_name(rp2350geek "rp2350geek")
pico_set_program_version(rp2350geek "0.01")

#to use this add CMakeList.txt to each sub folder
#add_subdirectory(lib/Config)
#add_subdirectory(lib/Infrared)
#add_subdirectory(lib/Images)
#add_subdirectory(lib/LCD)
#add_subdirectory(lib/Fonts)
#add_subdirectory(lib/GUI)
#add_subdirectory(c)


#not sure what this does
#include_directories(c)
#include_directories(lib/Config)
#include_directories(lib/GUI)
#include_directories(lib/Fonts)
#include_directories(lib/LCD)
#include_directories(lib/Infrared)
#include_directories(lib/Images)

# sdk libraries are linked in here. project sources are above.
target_link_libraries(rp2350geek
    hardware_pwm 
    hardware_i2c 
    pico_stdlib 
    pico_printf 
    pico_stdio_usb 
    hardware_spi 
    m
)

# enable usb output, disable uart output
pico_enable_stdio_usb(rp2350geek 1)
pico_enable_stdio_uart(rp2350geek 0)

# Turn on all warnings
target_compile_options(rp2350geek PRIVATE -Wall -Werror)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(rp2350geek)

