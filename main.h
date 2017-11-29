/*
 * main.h
 *
 *  Created on: 28.11.2017
 *      Author: vincent
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MCP2402 0
#define SPI_Debug 1
#define DEBUG 1

#include <wiringPi.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wiringPiSPI.h>

#include "MCP3204/MCP3204.h"
#include "LED_Stripe.h"
#include "MCP23S17/MCP23S17.h"

void ldr_print(uint16_t);


#endif /* MAIN_H_ */
