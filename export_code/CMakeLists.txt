# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(gui_guider)

FILE(GLOB app_sources src/*.c src/generated/*.c src/custom/*.c src/generated/guider_customer_fonts/*.c src/generated/guider_fonts/*.c src/generated/images/*.c)
target_include_directories(app PRIVATE src/generated src/custom src/generated/guider_customer_fonts src/generated/guider_fonts)
target_sources(app PRIVATE ${app_sources})
target_compile_definitions(app PRIVATE LV_LVGL_H_INCLUDE_SIMPLE)

target_sources_ifdef(CONFIG_FLASH_STM32_QSPI app PRIVATE boards/stm32f746g_disco/ext_mem_init.c)

# Run ext_code from the external flash (XIP). No need to copy.
zephyr_code_relocate(FILES src/generated/images/_slider_0_alpha_800x80.c LOCATION EXTFLASH_TEXT NOCOPY)

set(Ext_Data "void __attribute__((__weak__)) test(void){} const __attribute__((section(\".extflash_text_reloc\")))")
target_compile_definitions(app PRIVATE LV_ATTRIBUTE_MEM_ALIGN=${Ext_Data})


