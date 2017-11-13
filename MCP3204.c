/*
 * MCP3204.c
 *
 *  Created on: 08.11.2017
 *      Author: vincent
 */

#include "MCP3204.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>

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

	this->data.union_struct_rw.high = this->conf[1];
	this->data.union_struct_rw.low = this->conf[2];

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

//	this->conf[0] = 0x6;
//	this->conf[1] = 0x0;

//	this->data.union_struct_rw.high = this->conf[1];
//	this->data.union_struct_rw.low = this->conf[2];

	this->speed = speed;
	this->CS_ID = CS_ID;

	return 0;
}

int diff_read_analog(Diff_ChannelInstance this) {

	if (wiringPiSPISetupMode(this.CS_ID, this.speed, 0b11) < 0) {
		perror("diff_read_analog error");
		return (-1);
	}

	unsigned char *data;

	data = malloc(sizeof(*data));

	data = (unsigned char*) this.conf;

	wiringPiSPIDataRW(0, data, 3);

	this.data.union_struct_rw.high = data[1];
	this.data.union_struct_rw.low = data[0];

	return 0;
}

int sin_read_analog(Single_ChannelInstance* this) {

	if (wiringPiSPISetupMode(this->CS_ID, this->speed, 0b11) < 0) {
		perror("diff_read_analog error");
		return (-1);
	}

	unsigned char *data;

	data = malloc(sizeof(*data));

//	data = (unsigned char*) this->conf;

	data[0] = this->conf[0];
	data[1] = this->conf[1];



	wiringPiSPIDataRW(0, data, 3);

	this->data.union_struct_rw.high = data[1];
	this->data.union_struct_rw.low = data[0];

	return 0;
}

static Diff_ChannelClass diff_inst = { diff_setup, diff_read_analog };

Diff_ChannelInstance newDiffChannel() {

	Diff_ChannelInstance inst;

#if DEBUG
	puts("created new Diff_ChannelInstance");
#endif

	inst.CS_ID = 0;
	inst.conf = 0;
	inst.data.value = 0;
	inst.diff_ID = 0;
	inst.speed = 0;
	inst.clazz = &diff_inst;

	return inst;
}

static Single_ChannelClass sin_inst = { sin_setup, sin_read_analog };

Single_ChannelInstance* newSingleChannel() {

	Single_ChannelInstance *inst;

	inst = malloc(sizeof(Single_ChannelInstance));

#if DEBUG
	puts("created new Diff_ChannelInstance");
#endif

	inst->CS_ID = 0;
	inst->conf = 0;
	inst->data.value = 0;
	inst->sin_ID = 0;
	inst->speed = 0;
	inst->clazz = &sin_inst;

	return inst;
}

