/*
 * ldr_print.c
 *
 *  Created on: 29.11.2017
 *      Author: vincent
 */

#include "main.h"

void ldr_print(uint16_t value) {

	char prnt[100];
	memset(prnt, ' ', sizeof(prnt));
	(void) value;
	if (value > 500) {
		value -= 500;
	} else {

	}

	float tmp;
	tmp = (float) value;
	tmp = tmp / 4096;
	tmp = tmp * 100;
	value = (uint16_t) tmp;
	memset(prnt, '*', value);
//	prnt[value] = '*';

	printf("%s\n", prnt);

	return;
}
