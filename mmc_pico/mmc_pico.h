#include "pico/stdlib.h"
#include "hardware/spi.h" 
#include "ff.h"
#include "diskio.h"

/* Definitions for MMC/SDC command */
#define CMD0   (0)			/* GO_IDLE_STATE */
#define CMD1   (1)			/* SEND_OP_COND */
#define ACMD41 (41|0x80)	/* SEND_OP_COND (SDC) */
#define CMD8   (8)			/* SEND_IF_COND */
#define CMD9   (9)			/* SEND_CSD */
#define CMD10  (10)			/* SEND_CID */
#define CMD12  (12)			/* STOP_TRANSMISSION */
#define ACMD13 (13|0x80)	/* SD_STATUS (SDC) */
#define CMD16  (16)			/* SET_BLOCKLEN */
#define CMD17  (17)			/* READ_SINGLE_BLOCK */
#define CMD18  (18)			/* READ_MULTIPLE_BLOCK */
#define CMD23  (23)			/* SET_BLOCK_COUNT */
#define ACMD23 (23|0x80)	/* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24  (24)			/* WRITE_BLOCK */
#define CMD25  (25)			/* WRITE_MULTIPLE_BLOCK */
#define CMD41  (41)			/* SEND_OP_COND (ACMD) */
#define CMD55  (55)			/* APP_CMD */
#define CMD58  (58)			/* READ_OCR */

/* Card type flags (CardType) */
#define CT_MMC 0x01 /* MMC ver 3 */
#define CT_SD1 0x02 /* SD ver 1 */
#define CT_SD2 0x04 /* SD ver 2 */
#define CT_SDC (CT_SD1|CT_SD2) /* SD */
#define CT_BLOCK 0x08 /* Block addressing */

#ifndef PIN_MISO
#define PIN_MISO 4
#endif

#ifndef PIN_CS
#define PIN_CS 5
#endif

#ifndef PIN_SCK
#define PIN_SCK 6
#endif

#ifndef PIN_MOSI
#define PIN_MOSI 7
#endif

#ifndef SPI_PORT
#define SPI_PORT spi0
#endif

#ifndef SPI_SPEED
#define SPI_SPEED 15 * 1000 * 1000
#endif

#ifndef SPI_SPEED_LOW
#define SPI_SPEED_LOW 1 * 1000 * 1000
#endif