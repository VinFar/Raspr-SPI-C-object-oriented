/*
 * MCP3204.h
 *
 *  Created on: 07.11.2017
 *      Author: vincent
 */

#ifndef MCP3204_H_
#define MCP3204_H_

#define mvolt(x) ((float)(x))*(5000/4096)

typedef struct ADC_Channel_Class_struct {
	int (*Setup)(int channel, int speed);
} ChannelClass;

typedef struct ADC_Channel_Instance_struct {
	ChannelClass* clazz;
	int ID;
	int CS_ID;
	union adc data;
} ChannelInstance;

typedef struct Single_ADC_Channel_Class_struct {
	int (*Setup)(int channel, int speed);
	int (*RW_Data)(int channel, unsigned char *data, int len);
} Single_ChannelClass;

typedef struct Single_ADC_Channel_Instance_struct {
	Single_ChannelClass* clazz;
	int ID;
	int CS_ID;
	union adc data;
} Diff_InstanceClass;

typedef struct Diff_ADC_Channel_Class_struct {
	int (*Setup)(int channel, int speed);
	int (*RW_Data)(int channel, unsigned char *data, int len);
} Diff_ChannelClass;

typedef struct Diff_ADC_Channel_Instance_struct {
	Diff_ChannelClass* clazz;
	int ID;
	int CS_ID;
	union adc data;
} Diff_InstanceClass;

union ADC {
	uint16_t value;
	struct {
		uint8_t low;
		uint8_t high;
	};
} adc;

#endif /* MCP3204_H_ */
