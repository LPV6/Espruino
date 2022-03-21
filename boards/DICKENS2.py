#!/bin/false
# This file is part of Espruino, a JavaScript interpreter for Microcontrollers
#
# Copyright (C) 2013 Gordon Williams <gw@pur3.co.uk>
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
# ----------------------------------------------------------------------------------------
# This file contains information for a specific board - the available pins, and where LEDs,
# Buttons, and other in-built peripherals are. It is used to build documentation as well
# as various source and header files for Espruino.
# ----------------------------------------------------------------------------------------

import pinutils;

info = {
 'boardname' : "DICKENS",
 'link' :  [ "" ],
 'espruino_page_link' : '',
# 'default_console' : "EV_BLUETOOTH",
 'default_console' : "EV_SERIAL1",
 'default_console_rx' : "D44",
 'default_console_tx' : "D47",
 'default_console_baudrate' : "9600",
 'variables' : 5000, # How many variables are allocated for Espruino to use. RAM will be overflowed if this number is too high and code won't compile.
 'io_buffer_size' : 512,
 'bootloader' : 1,
 'binary_name' : 'firmware_%v_dickens.hex',
 'build' : {
   'optimizeflags' : '-Os',
   'libraries' : [
     'BLUETOOTH',
     'GRAPHICS',
     'LCD_SPI'
   ],
   'makefile' : [
#     'DEFINES += -DNRF_LOG_ENABLED=1 -DNRF_LOG_FILTERS_ENABLED=0',
     'DEFINES += -DCONFIG_NFCT_PINS_AS_GPIOS', # Allow us to use NFC pins as GPIO
     'DEFINES += -DESPR_LSE_ENABLE=1', # Ensure low speed external osc enabled
     'DEFINES += -DNRF_SDH_BLE_GATT_MAX_MTU_SIZE=131', # 23+x*27 rule as per https://devzone.nordicsemi.com/f/nordic-q-a/44825/ios-mtu-size-why-only-185-bytes
     'LDFLAGS += -Xlinker --defsym=LD_APP_RAM_BASE=0x2ec0', # set RAM base to match MTU
#     'DEFINES += -DESPR_REGOUT0_1_8V=1', # Leave REGOUT0 as 1.8v (not 3.3v) - seems to be what original watch firmware did  
     'DEFINES += -DESPR_DCDC_ENABLE=1', # Use DC/DC converter
     'ESPR_BLUETOOTH_ANCS=1', # Enable ANCS (Apple notifications) support
     'DEFINES += -DSPIFLASH_SLEEP_CMD', # SPI flash needs to be explicitly slept and woken up
     'DEFINES += -DESPR_USE_SPI3=1', # Use SPI3 (even though it has errata 195) as it's much faster
     'DEFINES += -DESPR_BACKLIGHT_FADE=1', # Smoothly fade backlight on and off
     'DEFINES += -DNRF_BL_DFU_ENTER_METHOD_BUTTON=1 -DNRF_BL_DFU_ENTER_METHOD_BUTTON_PIN=29',
     'DEFINES += -DNRF_BOOTLOADER_NO_WRITE_PROTECT=1', # By default the bootloader protects flash. Avoid this (a patch for NRF_BOOTLOADER_NO_WRITE_PROTECT must be applied first)
     'DEFINES += -DBUTTONPRESS_TO_REBOOT_BOOTLOADER',
     'DEFINES += -DESPR_BOOTLOADER_SPIFLASH', # Allow bootloader to flash direct from SPI flash
     'DEFINES += -DAPP_TIMER_OP_QUEUE_SIZE=6', # Bangle.js accelerometer poll handler needs something else in queue size

     'BOOTLOADER_SETTINGS_FAMILY = NRF52840',
     'DFU_PRIVATE_KEY=targets/nrf5x_dfu/dfu_private_key.pem',
     'DFU_SETTINGS=--application-version 0xff --hw-version 52 --sd-req 0xA9', # SD 6.0.0

     'DEFINES+=-DBLUETOOTH_NAME_PREFIX=\'"Chronomark"\'',
     'DEFINES+=-DCUSTOM_GETBATTERY=jswrap_banglejs_getBattery',
     'DEFINES+=-DDUMP_IGNORE_VARIABLES=\'"g\\0"\'',
     'DEFINES+=-DESPR_GRAPHICS_INTERNAL=1',
     'DEFINES+=-DUSE_FONT_6X8 -DGRAPHICS_PALETTED_IMAGES -DESPR_GRAPHICS_12BIT -DGRAPHICS_ANTIALIAS',
     'DEFINES+=-DNO_DUMP_HARDWARE_INITIALISATION', # don't dump hardware init - not used and saves 1k of flash
     'INCLUDE += -I$(ROOT)/libs/banglejs -I$(ROOT)/libs/misc',
     'WRAPPERSOURCES += libs/banglejs/jswrap_bangle.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_architekt10.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_architekt12.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_architekt15.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_architekt35.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_grotesk14.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_grotesk16.c',
     'WRAPPERSOURCES += libs/graphics/jswrap_font_grotesk20.c',
     'SOURCES += libs/misc/stepcount.c',
     'SOURCES += libs/banglejs/dickens_storage_default.c',
     'DEFINES += -DESPR_STORAGE_INITIAL_CONTENTS=1',
     'DEFINES += -DESPR_USE_STORAGE_CACHE=32', # Add a 32 entry cache to speed up finding files
     'JSMODULESOURCES += libs/js/banglejs/locale.min.js',
     'DEFINES += -DBANGLEJS',
     'DEFINES += -DESPR_NO_LOADING_SCREEN', # disable 'loading...' message when switching apps

     'NRF_SDK15=1'
   ]
 }
};


chip = {
  'part' : "NRF52840",
  'family' : "NRF52",
  'package' : "QFN48",
  'ram' : 256,
  'flash' : 1024,
  'speed' : 64,
  'usart' : 2,
  'spi' : 3,  # Also defined in nrf52840_peripherals.h
  'i2c' : 1,
  'adc' : 1,
  'dac' : 0,
  'saved_code' : {
    'address' : ((245 - 80) * 4096), # Bootloader takes pages 248-255, FS takes 246-247
    'page_size' : 4096,
    'pages' : 80,
    'flash_available' : 1024 - ((38 + 8 + 2 + 80)*4), # Softdevice uses 0x26=38 pages of flash, bootloader 8, FS 2, code 20. Each page is 4 kb.

    'address2' : 0x60000000, # put this in external spiflash (see below)
    'pages2' : 1024, # Entire 4MB of external flash
  },
};

devices = {
  'BTN1' : { 'pin' : 'D46', 'pinstate' : 'IN_PULLDOWN' }, # TR Pin negated in software
  'BTN2' : { 'pin' : 'D28', 'pinstate' : 'IN_PULLDOWN' }, # BR Pin negated in software
  'BTN3' : { 'pin' : 'D29', 'pinstate' : 'IN_PULLDOWN' }, # BL Pin negated in software
  'BTN4' : { 'pin' : 'D42', 'pinstate' : 'IN_PULLDOWN' }, # TL Pin negated in software

  'RX_PIN_NUMBER' : { 'pin' : 'D44'},
  'TX_PIN_NUMBER' : { 'pin' : 'D47'},

  'VIBRATE' : { 'pin' : 'D6' }, # Pin negated in software
  'LCD' : {
            'width' : 240, 'height' : 240, 'bpp' : 16, # 16 normal, 12 bit is possible
            'controller' : 'gc9a01',
            'pin_dc' : 'D7',
            'pin_cs' : 'D11',
            'pin_rst' : 'D40',
            'pin_sck' : 'D12',
            'pin_mosi' : 'D5',
            'pin_miso' : 'D27',
            'pin_en' : 'D43', 
            'pin_bl' : 'D32', # backlight negated in get_pins below
            'pin_tearing' : 'D24',
            'bitrate' : 32000000
          },
  'BAT' : {
            'pin_charging' : 'D13', 
            'pin_voltage' : 'D4'
          },
  'MAG' : { # Magnetometer/compass
           'device' : 'GMC303', 
           'addr' : 0x0C,
           'pin_sda' : 'D9',
           'pin_scl' : 'D10'
         },
  'ACCEL' : {
            'device'  : 'KX126', 'addr' : 0x1e,
            'pin_sda' : 'D9',
            'pin_scl' : 'D10',
            'pin_int1' : 'D23',
            'pin_int2' : 'D21'
         },
  'PRESSURE' : {
           'device' : 'SPL06_007', 'addr' : 0x76,
           'pin_sda' : 'D9',
           'pin_scl' : 'D10',
        },
  'SPIFLASH' : {
            'pin_cs' : 'D14',
            'pin_sck' : 'D19',
            'pin_mosi' : 'D18', # D0
            'pin_miso' : 'D15', # D1
            'pin_wp' : 'D16', # D2
            'pin_rst' : 'D17', # D3
            'size' : 8192*1024, # 64 Mbit (8 MB) flash
            'memmap_base' : 0x60000000 # map into the address space (in software)
          }
};

# left-right, or top-bottom order
board = {
  '_notes' : {
    'D44' : "Serial console RX",
    'D47' : "Serial console TX"
  }
};
board["_css"] = """
""";

def get_pins():
  pins = pinutils.generate_pins(0,47) # 48 General Purpose I/O Pins.
  pinutils.findpin(pins, "PD0", True)["functions"]["XL1"]=0;
  pinutils.findpin(pins, "PD1", True)["functions"]["XL2"]=0;
  pinutils.findpin(pins, "PD2", True)["functions"]["ADC1_IN0"]=0;
  pinutils.findpin(pins, "PD3", True)["functions"]["ADC1_IN1"]=0;
  pinutils.findpin(pins, "PD4", True)["functions"]["ADC1_IN2"]=0;
  pinutils.findpin(pins, "PD5", True)["functions"]["ADC1_IN3"]=0;
  pinutils.findpin(pins, "PD28", True)["functions"]["ADC1_IN4"]=0;
  pinutils.findpin(pins, "PD29", True)["functions"]["ADC1_IN5"]=0;
  pinutils.findpin(pins, "PD30", True)["functions"]["ADC1_IN6"]=0;
  pinutils.findpin(pins, "PD31", True)["functions"]["ADC1_IN7"]=0;
  # Make buttons and LEDs negated
  pinutils.findpin(pins, "PD29", True)["functions"]["NEGATED"]=0; # ok
  pinutils.findpin(pins, "PD46", True)["functions"]["NEGATED"]=0; # ok
  pinutils.findpin(pins, "PD42", True)["functions"]["NEGATED"]=0; # ok
  pinutils.findpin(pins, "PD28", True)["functions"]["NEGATED"]=0; # ok
  # Negate backlight
  pinutils.findpin(pins, "PD32", True)["functions"]["NEGATED"]=0; # ok
  

  # everything is non-5v tlerant
  for pin in pins:
    pin["functions"]["3.3"]=0;
  #The boot/reset button will function as a reset button in normal operation. Pin reset on PD21 needs to be enabled on the nRF52832 device for this to work.
  return pins
