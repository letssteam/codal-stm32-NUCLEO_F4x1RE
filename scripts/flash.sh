#!/bin/sh
set -e
./build.py
openocd -s "/usr/share/openocd/scripts/" -s"libraries/codal-stm32-NUCLEO_F4x1RE/scripts/" -f "openocd.cfg" -c "program NUCLEO_F4x1RE.hex verify reset exit "
