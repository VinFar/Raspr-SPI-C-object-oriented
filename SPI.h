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

int Open(const char *path,int flags);
int Ioctl(int fd,unsigned long spi_mode,unsigned long *mode);
int SpiWriteRead (int fd, unsigned char *data, int length);


#endif /* SPI_H_ */
