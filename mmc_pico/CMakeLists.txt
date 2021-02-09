project(FatFs_test)

add_library(common_stuff INTERFACE)
target_link_libraries(common_stuff INTERFACE
        pico_stdlib
        hardware_spi
        )
        
add_compile_definitions(mmc_pico
        PIN_MISO=4
        PIN_CS=5
        PIN_SCK=6
        PIN_MOSI=7
        SPI_PORT=spi0
        SPI_SPEED=15000000
        SPI_SPEED_LOW=1000000
        _USE_WRITE=1
        _USE_IOCTL=1
        )


add_library(mmc_pico STATIC mmc_pico.c)
target_link_libraries(mmc_pico common_stuff)
