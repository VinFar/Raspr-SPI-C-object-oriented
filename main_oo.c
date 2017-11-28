/*
 * main.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include <wiringPi.h>
#include <string.h>
#include "MCP3204.h"

#if SPI_Debug
#include <wiringPiSPI.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "LED_Stripe.h"
#endif

#define MCP2402 0

int main(int argv, char** argc) {

#if SPI_Debug
	wiringPiSetup();
	puts("SPI Modus");
	pinMode(29, OUTPUT);
//	LED(1);
//	pinMode(2, OUTPUT);
//	digitalWrite(2, HIGH);
	struct timeval time;
//	sleep(2);
	time.tv_sec = 10;
	time.tv_usec = 1;

#if MCP2402

	Sin_Channel_Instance sin1 = newSinChannel(sizeof(*sin1));
	Sin_Channel_Instance sin2 = newSinChannel(sizeof(*sin2));
	Diff_Channel_Instance diff1 = newDiffChannel(sizeof(*diff1));

	sin1->clazz->sin_setup(500000, 0, 0, sin1);
	sin2->clazz->sin_setup(500000, 1, 0, sin2);

	diff1->clazz->diff_setup(500000, 0b10, 0, diff1);

	while (1) {
		time.tv_sec = 0;
		time.tv_usec = 300000;

		sin1->clazz->sin_read_analog(sin1);
		sin2->clazz->sin_read_analog(sin2);
		diff1->clazz->diff_read_analog(diff1);

		LED_Stripe(sin2->data.value);
//
//		printf("%d		%d		%d\n", sin1->data.value, sin2->data.value,
//				diff1->data.value);
//
//		select(0, NULL, NULL, NULL, &time);

	}

#else

	int fd;

	if ((fd = wiringPiSPISetupMode(1, 500000, 0)) < 0) {
		perror("diff_read_analog error");
		return -1;
	}

	unsigned char data[3];

	data[0] = 0b01000000;
	data[1] = 0x0A;			//IOCON
	data[2] = 0b00100000;	//BANK=0, Address pointer does not increment

	digitalWrite(29, LOW);
	if (wiringPiSPIDataRW(1, data, 3) < 0)
		puts("err");
	digitalWrite(29, HIGH);

	data[0] = 0b01000000;
	data[1] = 0b00000000;	//IODIRA
	data[2] = 0b0;			//All pins at outputs

	if (wiringPiSPIDataRW(1, data, 3) < 0)
		puts("err2");

	printf("1: %d,2: %d,3: %d", data[0], data[1], data[2]);

	data[0] = 0b01000000;
	data[1] = 0b000000001;	//IODIRB
	data[2] = 0b0;			//All pins at output

	if (wiringPiSPIDataRW(1, data, 3) < 0)
		puts("err3");
	while (1) {
		data[0] = 0b01000000;
		data[1] = 0x12;			//GPIOA
		data[2] = 0b10101010;	//Set outputs

		if (wiringPiSPIDataRW(1, data, 3) < 0)
			puts("err4");

		data[0] = 0b01000000;
		data[1] = 0x12;			//GPIOA
		data[2] = 0b01010101;	//Set outputs

		if (wiringPiSPIDataRW(1, data, 3) < 0)
			puts("err4");
	}
	puts("fertig");
	close(fd);

	return 0;

#endif

#else

	wiringPiSetup();
	pinMode(0,OUTPUT);
	for (;;)
	{
		digitalWrite (0, HIGH); delay (2000);
		digitalWrite (0, LOW); delay (2000);
	}
	puts("Objektorientiert");

	bool test;
	test = 1;
	Circle circle1 = newCircle(5 , 5 , 5);

	circle1->clazz->move(circle1,10,10);

	Rect rect1 = newRect(555,555,55,55);

	rect1->clazz->draw(rect1);
#endif

	return 0;
}

