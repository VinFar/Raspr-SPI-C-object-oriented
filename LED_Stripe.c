/*
 * LED_Stripe.c
 *
 *  Created on: 20.11.2017
 *      Author: vincent
 */
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "LED_Stripe.h"
#include <wiringPi.h>

void LED(uint16_t s) {

	for (int i = 1; i < 9; i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, HIGH);
		pullUpDnControl(i,PUD_OFF);
	}

}

void LED_Stripe(uint16_t data) {
	int32_t value;
	value = data > 1000 ? (data - 1000) : 0;

	for (int i = 1; i < 9; i++) {

		if (value > 0) {
			digitalWrite(i, HIGH);
		} else {
			digitalWrite(i, LOW);
		}
		if (value > 250) {
			value -= 250;
		}else{
			value = 0;
		}

//		printf("data %d: %d  \n",i, value);

	}
	return;
}
