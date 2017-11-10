/*
 * MCP3204.c
 *
 *  Created on: 08.11.2017
 *      Author: vincent
 */

#include "MCP3204.h"
#include <stdlib.h>
#include <errno.h>

int diff_setup(int speed, unsigned int diff_ID, int CS_ID,
		Diff_ChannelInstance *this) {

	if (diff_ID > 4) {
//		errno = "Bad diff_ID";
		return -1;
	}
	if (CS_ID > 2) {
//		errno = "Bad CS_ID";
		return -1;
	}

	if (speed < 500000 || speed > 2000000) {
//		errno = "Not supported speed value";
		return -1;
	}

	this->conf = malloc(3);

	this->conf[0] = (diff_ID >> 2) | 0b100;
	this->conf[1] = ((diff_ID & 0b11) << 6);
	this->conf[2] = 0;

	this->speed = speed;
	this->CS_ID = CS_ID;

	return 0;
}

int sin_setup(int speed, unsigned int sin_ID, int CS_ID,
		Single_ChannelInstance *this) {

	if (sin_ID > 4) {
//		errno = "Bad diff_ID";
		return -1;
	}
	if (CS_ID > 2) {
//		errno = "Bad CS_ID";
		return -1;
	}

	if (speed < 500000 || speed > 2000000) {
//		errno = "Not a supported speed value";
		return -1;
	}

	this->conf = malloc(3);

	this->conf[0] = (sin_ID >> 2) | 0b110;
	this->conf[1] = ((sin_ID & 0b11) << 6);
	this->conf[2] = 0;

	this->speed = speed;
	this->CS_ID = CS_ID;

	return 0;
}

int read_analog(Single_ChannelInstance this){


	return 0;
}

static Diff_ChannelClass diff_class = {diff_setup,read_analog};

Diff_ChannelInstance newDiffChannel(){

	Diff_ChannelInstance inst;

	inst.clazz = &diff_class;

	return inst;
}


