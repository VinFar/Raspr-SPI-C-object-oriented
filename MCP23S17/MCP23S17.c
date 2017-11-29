/*
 * MCP23S17.c
 *
 *  Created on: 28.11.2017
 *      Author: vincent
 */

#include "../main.h"

int write_register(unsigned char address_ptr, unsigned char value,
		PRTEXP_MCP_Instance this) {
	unsigned char *data;

	data = malloc(3 * sizeof(unsigned char));

	data[0] = /*(this->mcp_address & 0b11111110) |*/0b01000000;
	data[1] = address_ptr;
	data[2] = value;

	int fd;

	if ((fd = wiringPiSPISetupMode(this->CS_ID, this->speed, 0)) < 0) {
		perror("err: could not write register");
		return -1;
	}

	if (wiringPiSPIDataRW(this->CS_ID, data, 3) < 0) {
		puts("err: could not write register!");
		return -1;
	}

	close(fd);
	free(data);

	return 0;

}

unsigned char read_register(unsigned char address_pointer,
		PRTEXP_MCP_Instance this) {

	unsigned char *data;

	data = malloc(3 * sizeof(unsigned char));

	data[0] = (this->mcp_address & 0b11111110) | 0b01000001;
	data[1] = address_pointer;
	data[2] = 0;

	int fd;

	if ((fd = wiringPiSPISetupMode(this->CS_ID, this->speed, 0)) < 0) {
		perror("err: could not read register");
		return -1;
	}

	if (wiringPiSPIDataRW(this->CS_ID, data, 3) < 0) {
		puts("err: could not read register!");
		return -1;

	}

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

	data[0] = 0b01000000;	//(this->mcp_address & 0b11111110) | 0b01;

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
		perror("err: could not write register");
		return -1;
	}

	if (wiringPiSPIDataRW(this->CS_ID, data, 3) < 0) {
		puts("err: could not write register!");
		return -1;
	}

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

	printf("union: %d	\n", (int) mcp_address.OpCode);

	this->CS_ID = CS_ID;
	this->speed = speed;
	this->mcp_address = mcp_address.OpCode;
	this->last_address_ptr = 0x0;
	this->last_registervalue = 0x0;

}

void mcp_bargraph(uint16_t value, PRTEXP_MCP_Instance this) {

	if (value > 500) {
		value -= 500;
	} else {
		this->clazz->set_output_pins(GPIOA, 0, this);
		this->clazz->set_output_pins(GPIOB, 0, this);
		return;
	}

	union gpio {
		uint16_t big;
		unsigned char little[2];
	} gpio_u;
	int shift = 0;
	gpio_u.big = 0;

	while (value > 0) {
		gpio_u.big += 1 << shift++;
		if (value > 225) {
			value -= 225;
		} else {
			break;
		}
	}
	this->clazz->set_output_pins(GPIOA, gpio_u.little[0], this);
	this->clazz->set_output_pins(GPIOB, gpio_u.little[1], this);

}

static PRTEXP_MCP_Class class = { write_register, read_register,
		set_output_pins, mcp_setup,mcp_bargraph };

PRTEXP_MCP_Instance new_PRTEXP() {

	PRTEXP_MCP_Instance inst;
	printf("sizeof2: %d\n", sizeof(*inst));
	inst = malloc(sizeof(*inst));

	inst->CS_ID = 0;
	inst->last_address_ptr = 0;
	inst->last_registervalue = 0;
	inst->mcp_address = 0;
	inst->speed = 0;
	inst->clazz = &class;

	return inst;
}
