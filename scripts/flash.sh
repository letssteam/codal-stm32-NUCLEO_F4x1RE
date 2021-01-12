#!/bin/sh
set -e
./build.py
openocd -s "/usr/share/openocd/scripts/" -s"libraries/codal-stm32-NUCLEO_F411RE/scripts/" -f "openocd.cfg" -c "program NUCLEO_F411RE.hex verify reset exit "
