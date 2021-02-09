project(FatFs_test)

add_compile_definitions(ff
        FF_USE_STRFUNC=1
        )
        
add_library(ff STATIC ff.c)
