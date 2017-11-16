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


#define SPI_Debug 1
#define DEBUG 1

/*#define mcp_error(x) printf("x: ")
 #define set_error(x)	mcp_string = malloc(sizeof(#x)) \
						*mcp_string = #x
 */

char *mcp_string;

#define mvolt(x) ((float)(x))*(5000/4096)

#define BEG_DEFINE_SIN_CLASS(T) typedef struct Sin_ADC_##T##_Instance_struct* T;\
		typedef struct Sin_ADC_##T##_Class_struct {

#define END_DEFINE_SIN_CLASS(T) } Sin_##T##Class;



#define BEG_DEFINE_SIN_INSTANCE(T) typedef struct Sin_ADC_##T##_Instance_struct {

#define END_DEFINE_SIN_INSTANCE	} Sin_##Instance;



#define INSTANCE_OF(T) T##_CHANNEL_ATTRIBUTES


#define METHODS(T)	T##_METHODS

#define ATTRIBUTES(T) T##_ATTRIBUTES



#define	ADC_CHANNEL_ATTRIBUTES	union ADC data; \
								int CS_ID; \
								int speed; \
								char *conf;


#define Sin_ATTRIBUTES	Single_ChannelClass *clazz;\
						int sin_ID;

#define Diff_ATTRIBUTES	Diff_ChannelClass* clazz;\
						int diff_ID;



#define Sin_METHODS int (*sin_setup)(int speed, unsigned int sin_ID, unsigned int CS_ID, \
					Single_ChannelInstance *this);\
					int (*sin_read_analog)(Single_ChannelInstance* this);

#define Diff_METHODS	int (*diff_setup)(int speed, unsigned int diff_ID, unsigned int CS_ID, \
						Diff_ChannelInstance* this); \
						int (*diff_read_analog)(Diff_ChannelInstance* this);





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

typedef struct Sin_ADC_Channel_Instance_struct* Sin_ChannelInstance;
typedef struct Sin_ADC_Channel_Class_struct {
	int (*sin_setup)(int speed, unsigned int sin_ID, unsigned int CS_ID,
			Sin_ChannelInstance this);
	int (*sin_read_analog)(Sin_ChannelInstance this);
} Sin_ChannelClass;

typedef struct Sin_ADC_Channel_Instance_struct {
	Sin_ChannelClass *clazz;
	union ADC data;
	int CS_ID;
	int speed;
	char *conf;
	int sin_ID;
}Sin_ADC_Channel_Instance;

typedef struct Diff_ADC_Channel_Instance_struct* Diff_ChannelInstance;
typedef struct Diff_ADC_Channel_Class_struct {
	int (*diff_setup)(int speed, unsigned int diff_ID, unsigned int CS_ID,
			Diff_ChannelInstance this);
	int (*diff_read_analog)(Diff_ChannelInstance this);
} Diff_ChannelClass;

typedef struct Diff_ADC_Channel_Instance_struct {
	Diff_ChannelClass* clazz;
	union ADC data;
	int CS_ID;
	int speed;
	char *conf;
	int diff_ID;
} Diff_ADC_Channel_Instance;

int diff_setup(int speed, unsigned int diff_ID, unsigned int CS_ID,
		Diff_ChannelInstance this);
Diff_ChannelInstance newDiffChannel();


int read_analog(Sin_ChannelInstance this);


Sin_ChannelInstance newSingleChannel();
int sin_setup(int speed, unsigned int sin_ID,unsigned int CS_ID,
		Sin_ChannelInstance this);


#endif /* MCP3204_H_ */
