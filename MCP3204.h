/*
 * MCP3204.h
 *
 *  Created on: 07.11.2017
 *      Author: vincent
 */

#ifndef MCP3204_H_
#define MCP3204_H_

#include <unistd.h>
#include <stdint.h>
#include <errno.h>

/*#define mcp_error(x) printf("x: ")
 #define set_error(x)	mcp_string = malloc(sizeof(#x)) \
						*mcp_string = #x
 */

char *mcp_string;

#define mvolt(x) ((float)(x))*(5000/4096)
//
union ADC {
	uint16_t value;
	struct union_struct_rw {
		uint8_t low;
		uint8_t high;
	} union_struct_rw;
} adc;



typedef struct ADC_Channel_Instance_struct {
	union ADC data;
	int CS_ID;
	int speed;
	char *conf;
} ChannelInstance;

typedef struct Single_ADC_Channel_Instance_struct Single_ChannelInstance;
typedef struct Single_ADC_Channel_Class_struct {
	int (*sin_setup)(int speed, unsigned int sin_ID, int CS_ID,
			Single_ChannelInstance *this);
	int (*read_analog)(Single_ChannelInstance this);
} Single_ChannelClass;

struct Single_ADC_Channel_Instance_struct {
	Single_ChannelClass *clazz;
	union ADC data;
	int CS_ID;
	int speed;
	char *conf;
	int sin_ID;
};

typedef struct Diff_ADC_Channel_Instance_struct Diff_ChannelInstance;
typedef struct Diff_ADC_Channel_Class_struct {
	int (*diff_setup)(int speed, unsigned int diff_ID, int CS_ID,
			Diff_ChannelInstance *this);
	int (*read_analog)(Single_ChannelInstance this);
} Diff_ChannelClass;

struct Diff_ADC_Channel_Instance_struct {
	Diff_ChannelClass* clazz;
	union ADC data;
	int CS_ID;
	int speed;
	char *conf;
	int diff_ID;
};

int diff_setup(int speed, unsigned int diff_ID, int CS_ID,
		Diff_ChannelInstance *this);
int sin_setup(int speed, unsigned int sin_ID, int CS_ID,
		Single_ChannelInstance *this);
Diff_ChannelInstance newDiffChannel();
int read_analog(Single_ChannelInstance this);

#endif /* MCP3204_H_ */
