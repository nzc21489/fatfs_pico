/*----------------------------------------------------------------------*/
/* Foolproof FatFs sample project for AVR              (C)ChaN, 2014    */
/*----------------------------------------------------------------------*/
/* Ported to Raspberry Pi Pico by nzc21489                              */
/*----------------------------------------------------------------------*/

#include "pico/stdlib.h"	/* Device specific declarations */
#include <stdio.h>
#include "ff.h"		/* Declarations of FatFs API */

#define LED 25

FATFS FatFs;		/* FatFs work area needed for each volume */
FIL Fil;			/* File object needed for each open file */


int main (void)
{
	UINT bw;
	FRESULT fr;

	stdio_init_all();

	sleep_ms(3000);

	printf("\nFatFs module test for Raspberry Pi Pico\n");
	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */

	fr = f_open(&Fil, "newfile.txt", FA_WRITE | FA_CREATE_ALWAYS);	/* Create a file */
	if (fr == FR_OK) {
		f_write(&Fil, "It works!\r\n", 11, &bw);	/* Write data to the file */
		fr = f_close(&Fil);							/* Close the file */
		if (fr == FR_OK && bw == 11) {		/* Lights LED if data written well */
			gpio_put(LED, 1);
			printf("Write Success\n");
		}else{
			printf("Write failure\n");
		}
	}else{
		printf("Cannot open file\n");
	}

	for (;;) ;
}