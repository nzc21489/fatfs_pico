# FatFs Media Access Interface for Raspberry Pi Pico

This is FatFs Media Access Interface implementation for Raspberry Pi Pico using SPI.

FatFs is a generic FAT/exFAT filesystem module for small embedded systems being developed by ChaN.

SD card/MMC can be used.

FatFs is not included in this repository. FatFs can be downloaded from http://elm-chan.org/fsw/ff/00index_e.html.

Extract files in source directory in FatFs zip file to fatfs_pico/fatfs directory.

## Building an example
```sh
cd path_to_fatfs_pico
cp path_to_pico-sdk/external/pico_sdk_import.cmake ./
export PICO_SDK_PATH=path_to_pico-sdk
mkdir build
cd build
cmake ..
make
```

## Wiring information
 * GP4 : MISO
 * GP5 : CS
 * GP6 : SCK
 * GP7 : MOSI
 
 These pins can be changed by editing mmc_pico/CMakeLists.txt.