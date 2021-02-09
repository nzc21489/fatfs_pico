project(FatFs_test)

add_executable(FatFs_test
        FatFs_test.c
        )
        
target_link_libraries(FatFs_test pico_stdlib hardware_spi ff mmc_pico)

pico_enable_stdio_usb(FatFs_test 1)

pico_add_extra_outputs(FatFs_test)
