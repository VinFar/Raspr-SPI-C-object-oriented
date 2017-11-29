/*
 * main.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */


#include <wiringPi.h>
#include <string.h>
#include "MCP3204/MCP3204.h"
#include "MCP23S17/MCP23S17.h"
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
	ldr_print(2000);
	puts("SPI Modus");

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
		time_s.tv_usec = 10000;

		sin1->clazz->sin_read_analog(sin1);
		sin2->clazz->sin_read_analog(sin2);
		diff1->clazz->diff_read_analog(diff1);

//		printf("%d		%d		%d\n", sin1->data.value, sin2->data.value,
//				diff1->data.value);

		ldr_print(sin2->data.value);

		select(0, NULL, NULL, NULL, &time_s	);

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


		select(0, NULL, NULL, NULL, &time_s);
		time_s.tv_sec = 0;
		time_s.tv_usec = 10000;


		sin1->clazz->sin_read_analog(sin1);
		sin2->clazz->sin_read_analog(sin2);
		diff1->clazz->diff_read_analog(diff1);

		PRT->clazz->mcp_bargraph(sin2->data.value,PRT);
		ldr_print(sin2->data.value);
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

