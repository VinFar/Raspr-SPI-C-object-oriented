/*
 * SPI.h
 *
 *  Created on: 02.11.2017
 *      Author: vincent
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

typedef struct SPI_DATA{

	struct spi_ioc_transfer *spi_data;
	int fd;
	unsigned char data;
	unsigned long bits;
	unsigned long speed;
	int ret;

}SPI_t;

int Open(const char *path,int flags);
int Ioctl(int fd,unsigned long spi_mode,unsigned long *mode);
void SpiWriteRead(SPI_t spi);




#endif /* SPI_H_ */
