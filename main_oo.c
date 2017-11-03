/*
 * main.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "SPI.h"

#define SPI_Debug 0

int main(int argv, char** argc){


#if SPI_Debug
	puts("hallo");
	static const char *device = "/dev/spidev0.0";
	static unsigned long mode;
	static unsigned long bits = 8;
	static unsigned long speed = 500000;
	int ret, fd;
	unsigned char *data = (unsigned char*)'c';



	/*open device*/
	fd = Open(device,O_RDWR);

	Ioctl(fd,SPI_IOC_RD_MODE,&mode);	/*set mode*/

	Ioctl(fd,SPI_IOC_RD_BITS_PER_WORD,&bits);	/*set word length*/

	Ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);	/*set data rate*/

	ret = SpiWriteRead(fd,data,sizeof(data));

	printf("rcvd: %c",ret);
#else
	puts("Objektorientiert");

	Circle circle1 = newCircle(5 , 5 , 5);

	circle1->clazz->move(circle1,10,10);

	Rect rect1 = newRect(555,555,55,55);

	rect1->clazz->draw(rect1);
#endif

	return 0;
}


