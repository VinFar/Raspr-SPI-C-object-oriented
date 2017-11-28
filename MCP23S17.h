/*
 * MCP23S17.h
 *
 *  Created on: 28.11.2017
 *      Author: vincent
 */

#ifndef MCP23S17_H_
#define MCP23S17_H_

#include "main.h"

union MCP_ADDRESS{
	unsigned char OpCode;
	unsigned A2;
	unsigned A1;
	unsigned A0;
	unsigned RW;
};

#define GPIOA 47
#define GPIOB 96


#define BEG_DEFINE_PRTEXP_CLASS(T)	typedef struct PRTEXP_##T##_Instance_struct* PRTEXP_##T##_Instance;\
								typedef struct PRTEXP_##T##_Class_struct {

#define END_DEFINE_PRTEXP_CLASS(T) } PRTEXP_##T##_Class;


#define BEG_DEFINE_PRTEXP_INSTANCE(T) typedef struct PRTEXP_##T##_Instance_struct {

#define END_DEFINE_PRTEXP_INSTANCE } PRTEXP_##T;

#define PRTEXP_ATTRIBUTES	unsigned char mcp_address; \
							unsigned char last_address_ptr; \
							unsigned char last_registervalue; \
							int speed; \
							unsigned int CS_ID;

#define PRTEXP_METHODS	int (*write_register)(unsigned char address_ptr,unsigned char value,PRTEXP_MCP_Instance this);\
						unsigned char (*read_register)(unsigned char address_pointer, PRTEXP_MCP_Instance this); \
						int (*set_output_pins)(unsigned char BANK,unsigned char pins); \
						void (*mcp_setup)(int speed,unsigned int CS_ID,union MCP_ADDRESS mcp_address,PRTEXP_MCP_Instance this);


BEG_DEFINE_PRTEXP_CLASS(MCP)
PRTEXP_METHODS
END_DEFINE_PRTEXP_CLASS(MCP)

BEG_DEFINE_PRTEXP_INSTANCE(MCP)
PRTEXP_ATTRIBUTES
END_DEFINE_PRTEXP_INSTANCE


#endif /* MCP23S17_H_ */
