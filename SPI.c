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

void SpiWriteRead(SPI_t spi)
{
	Ioctl(spi.fd, SPI_IOC_RD_BITS_PER_WORD, &spi.bits);

	Ioctl(spi.fd, SPI_IOC_RD_MAX_SPEED_HZ, &spi.speed);

		spi.spi_data->tx_buf = spi.data;
		spi.spi_data->rx_buf = spi.data;
		spi.spi_data->len = sizeof(spi.data);
		spi.spi_data->delay_usecs = 0;
		spi.spi_data->speed_hz = spi.speed;
		spi.spi_data->bits_per_word = spi.bits;
		spi.spi_data->cs_change = 0;

	puts("test");
	spi.ret = Ioctl(spi.fd, SPI_IOC_MESSAGE(1), (void*)spi.spi_data);

	return;
}
