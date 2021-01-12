#!/bin/sh
arm-none-eabi-gdb --eval "target remote | openocd -s /usr/share/openocd/scripts/ -s libraries/codal-stm32-NUCLEO_F411RE/scripts/ -f openocd.cfg -f debug.cfg" build/NUCLEO_F411RE
