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
#include <time.h>
#include <stdlib.h>

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
	struct timeval time_s;
//	sleep(2);
	time_s.tv_sec = 10;
	time_s.tv_usec = 1;

#if MCP2402

	Sin_Channel_Instance sin1 = newSinChannel(sizeof(*sin1));
	Sin_Channel_Instance sin2 = newSinChannel(sizeof(*sin2));
	Diff_Channel_Instance diff1 = newDiffChannel(sizeof(*diff1));

	sin1->clazz->sin_setup(500000, 0, 0, sin1);
	sin2->clazz->sin_setup(500000, 1, 0, sin2);

	diff1->clazz->diff_setup(500000, 0b10, 0, diff1);

	while (1) {
		time_s.tv_sec = 0;
		time_s.tv_usec = 300000;

		sin1->clazz->sin_read_analog(sin1);
		sin2->clazz->sin_read_analog(sin2);
		diff1->clazz->diff_read_analog(diff1);

//		LED_Stripe(sin2->data.value);
//
		printf("%d		%d		%d\n", sin1->data.value, sin2->data.value,
				diff1->data.value);

		select(0, NULL, NULL, NULL, &time);

	}

#else
	srand(time(NULL));
	PRTEXP_MCP_Instance PRT;

	PRT = new_PRTEXP();

	union MCP_ADDRESS mcp;
	mcp.OpCode = 0;
	mcp.bits.A0 = 0;
	mcp.bits.A1 = 0;
	mcp.bits.A2 = 0;

	PRT->clazz->mcp_setup(500000, 1, mcp, PRT);
	PRT->clazz->write_register(0x0A, 0b00100000, PRT);	//IOCON
	PRT->clazz->write_register(0x00, 0x00, PRT);
	PRT->clazz->write_register(0x01, 0x00, PRT);
	time_s.tv_sec = 0;
	time_s.tv_usec = 300000;


	Sin_Channel_Instance sin1 = newSinChannel(sizeof(*sin1));
	Sin_Channel_Instance sin2 = newSinChannel(sizeof(*sin2));
	Diff_Channel_Instance diff1 = newDiffChannel(sizeof(*diff1));

	sin1->clazz->sin_setup(500000, 0, 0, sin1);
	sin2->clazz->sin_setup(500000, 1, 0, sin2);

	diff1->clazz->diff_setup(500000, 0b10, 0, diff1);

	while (1) {


//		select(0, NULL, NULL, NULL, &time_s);
		time_s.tv_sec = 0;
		time_s.tv_usec = 100000;


		sin1->clazz->sin_read_analog(sin1);
		sin2->clazz->sin_read_analog(sin2);
		diff1->clazz->diff_read_analog(diff1);

		PRT->clazz->mcp_bargraph(sin2->data.value,PRT);

//		PRT->clazz->set_output_pins(GPIOA, rand(), PRT);
//		PRT->clazz->set_output_pins(GPIOB, rand(), PRT);
//		select(0, NULL, NULL, NULL, &time_s);
//		PRT->clazz->set_output_pins(GPIOA, rand(), PRT);
//		PRT->clazz->set_output_pins(GPIOB, rand(), PRT);
//		time_s.tv_sec = 0;
//		time_s.tv_usec = 100000;
//		puts("while");
//		select(0, NULL, NULL, NULL, &time_s);
//		time_s.tv_sec = 0;
//		time_s.tv_usec = 100000;

	}

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

	if (wiringPiSPIDataRW(1, data, 3) < 0) {
		puts("err3");
	}

	data[0] = 0b01000000;
	data[1] = 0x12;			//GPIOA
	data[2] = 0b01111101;	//Set outputs

	if (wiringPiSPIDataRW(1, data, 3) < 0)
		puts("err4");
//	while (1)
//		;
	while (1) {

		data[0] = 0b01000000;
		data[1] = 0x12;			//GPIOA
		data[2] = 0b00101000;	//Set outputs

		if (wiringPiSPIDataRW(1, data, 3) < 0)
			puts("err4");
//		for(int i=0;i<10000000;i++);
		puts("while");
		data[0] = 0b01000000;
		data[1] = 0x12;			//GPIOA
		data[2] = 0b00010111;	//Set outputs

		if (wiringPiSPIDataRW(1, data, 3) < 0)
			puts("err4");
//		for(int i=0;i<10000000;i++);
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

