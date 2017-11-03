/*
 * SPI.c
 *
 *  Created on: 02.11.2017
 *      Author: vincent
 */

#include "SPI.h"

int Open(const char *path, int flags) {

	int ret;

	if ((ret = open(path, flags)) < 0) {

		perror("open error");
		exit(-1);
	}

	return ret;
}

int Ioctl(int fd, unsigned long spi_mode,unsigned long *mode) {

	int ret;

	if ((ret = ioctl(fd, spi_mode, mode)) < 0) {

		perror("ioctl error");
		exit(-1);
	}

	return ret;
}

int SpiWriteRead(int fd, unsigned char *data, int length)

{
	struct spi_ioc_transfer spi_data[10];
	unsigned long bits = 8;
	unsigned long speed = 500000;
	int i, ret;

	Ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);

	Ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);

	for (i = 0; i < length; i++) {
		spi_data[i].tx_buf = (unsigned long) (data + i);
		spi_data[i].rx_buf = (unsigned long) (data + i);
		spi_data[i].len = sizeof(*(data + i));
		spi_data[i].delay_usecs = 0;
		spi_data[i].speed_hz = speed;
		spi_data[i].bits_per_word = bits;
		spi_data[i].cs_change = 0;
	}
	puts("test");
	ret = Ioctl(fd, SPI_IOC_MESSAGE(length), &spi_data);

	return ret;
}
