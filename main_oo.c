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
#endif

int main(int argv, char** argc) {

#if SPI_Debug
	puts("SPI Modus");

	struct timeval time;

	time.tv_sec = 10;
	time.tv_usec = 1;



	Single_ChannelInstance* sin1 = newSingleChannel();
	Single_ChannelInstance* sin2 = newSingleChannel();
	Diff_ChannelInstance* diff1 = newDiffChannel();

	sin1->clazz->sin_setup(500000, 0, 0, sin1);
	sin2->clazz->sin_setup(500000, 1, 0, sin2);


	diff1->clazz->diff_setup(500000, 0b10, 0, diff1);

	while (1) {
		time.tv_sec = 0;
		time.tv_usec = 300000;

		sin1->clazz->sin_read_analog(sin1);
		sin2->clazz->sin_read_analog(sin2);
		diff1->clazz->diff_read_analog(diff1);


	printf("%d		%d		%d\n", sin1->data.value, sin2->data.value,
				diff1->data.value);

		select(0, NULL, NULL, NULL, &time);

	}

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

