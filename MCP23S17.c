/*
 * MCP23S17.c
 *
 *  Created on: 28.11.2017
 *      Author: vincent
 */

#include "main.h"

int write_register(unsigned char address_ptr, unsigned char value,
		PRTEXP_MCP_Instance this) {
	unsigned char *data;

	data = malloc(3 * sizeof(unsigned char));

	data[0] = (this->mcp_address & 0b11111110);
	data[1] = address_ptr;
	data[2] = value;

	int fd;

	if ((fd = wiringPiSPISetupMode(this->CS_ID, this->speed, 0)) < 0) {
		perror("err: could not write register");
		return -1;
	}

	wiringPiSPIDataRW(0, data, 3);

	close(fd);
	free(data);

	return 0;

}

unsigned char read_register(unsigned char address_pointer,
		PRTEXP_MCP_Instance this) {

	unsigned char *data;

	data = malloc(3 * sizeof(unsigned char));

	data[0] = (this->mcp_address & 0b11111110) | 0b01;
	data[1] = address_pointer;
	data[2] = 0;

	int fd;

	if ((fd = wiringPiSPISetupMode(this->CS_ID, this->speed, 0)) < 0) {
		perror("err: could not read register");
		return -1;
	}

	wiringPiSPIDataRW(0, data, 3);

	this->last_address_ptr = address_pointer;
	this->last_registervalue = data[3];

	close(fd);
	free(data);

	return data[3];
}

int set_output_pins(unsigned char BANK, unsigned char pins,
		PRTEXP_MCP_Instance this) {

	unsigned char *data;

	data = malloc(3 * sizeof(unsigned char));

	data[0] = (this->mcp_address & 0b11111110) | 0b01;

	if (BANK == GPIOA) {
		data[1] = 0x12;
	} else if (BANK == GPIOB) {
		data[1] = 0x13;
	} else {
		puts("err: bad BANK!");
		return -1;
	}
	data[2] = pins;

	this->last_address_ptr = data[1];
	this->last_registervalue = data[3];

	int fd;

	if ((fd = wiringPiSPISetupMode(this->CS_ID, this->speed, 0)) < 0) {
		perror("err: could not read register");
		return -1;
	}

	wiringPiSPIDataRW(0, data, 3);

	close(fd);
	free(data);
	return 0;
}

void mcp_setup(int speed, unsigned int CS_ID, union MCP_ADDRESS mcp_address,
		PRTEXP_MCP_Instance this) {

	if (CS_ID > 1) {
		puts("err: CS_ID > 1!");
		exit(-1);
	}
	if (speed < 500000 || speed > 2000000) {
		puts("err: not supported speed!");
		exit(-1);
	}
	if (this == NULL) {
		puts("err: inst ptr is NULL!");
		exit(-1);
	}
	if (mcp_address.OpCode > 79) {
		puts("err: bad mcp_address union!");
		exit(-1);
	}

	this->CS_ID = CS_ID;
	this->speed = speed;
	this->mcp_address = mcp_address.OpCode;
	this->last_address_ptr = 0x0;
	this->last_registervalue = 0x0;

}

PRTEXP_MCP_Instance new_PRTEXP() {

	PRTEXP_MCP_Instance inst;

	inst = malloc(sizeof(*inst));

	inst->CS_ID = 0;
	inst->last_address_ptr = 0;
	inst->last_registervalue = 0;
	inst->mcp_address = 0;
	inst->speed = 0;

	return inst;
}
