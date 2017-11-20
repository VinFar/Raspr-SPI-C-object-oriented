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

#define mvolt(x) (float)((float)(x))*(5000/4096)

#define BEG_DEFINE_SIN_CLASS(T)	typedef struct Sin_##T##_Instance_struct* Sin_##T##_Instance;\
								typedef struct Sin_##T##_Class_struct {

#define END_DEFINE_SIN_CLASS(T) } Sin_##T##_Class;



#define BEG_DEFINE_SIN_INSTANCE(T) typedef struct Sin_##T##_Instance_struct {

#define END_DEFINE_SIN_INSTANCE	}Sin_##T;



#define BEG_DEFINE_DIFF_CLASS(T)	typedef struct Diff_##T##_Instance_struct* Diff_##T##_Instance;\
									typedef struct Diff_##T##_Class_struct {

#define END_DEFINE_DIFF_CLASS(T)	} Diff_##T##_Class;


#define BEG_DEFINE_DIFF_INSTANCE(T)		typedef struct Diff_##T##_Instance_struct {

#define END_DEFINE_DIFF_INSTANCE } Diff_##T;

#define INSTANCE_OF(T) T##_CHANNEL_ATTRIBUTES


#define METHODS(T)	T##_METHODS

#define ATTRIBUTES(T) T##_ATTRIBUTES



#define	ADC_CHANNEL_ATTRIBUTES	union ADC data; \
								int CS_ID; \
								int speed; \
								char *conf;


#define Sin_ATTRIBUTES	Sin_Channel_Class *clazz;\
						int sin_ID;

#define Diff_ATTRIBUTES	Diff_Channel_Class* clazz;\
						int diff_ID;



#define Sin_METHODS int (*sin_setup)(int speed, unsigned int sin_ID, unsigned int CS_ID, \
					Sin_Channel_Instance this);\
					int (*sin_read_analog)(Sin_Channel_Instance this);

#define Diff_METHODS	int (*diff_setup)(int speed, unsigned int diff_ID, unsigned int CS_ID, \
						Diff_Channel_Instance this); \
						int (*diff_read_analog)(Diff_Channel_Instance this);





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
} Channel_Instance;

BEG_DEFINE_SIN_CLASS(Channel)
METHODS(Sin)
END_DEFINE_SIN_CLASS(Channel)

BEG_DEFINE_SIN_INSTANCE(Channel) INSTANCE_OF(ADC)
ATTRIBUTES(Sin)
END_DEFINE_SIN_INSTANCE

//typedef struct Sin_Channel_Instance_struct* Sin_Channel_Instance;
//typedef struct Sin_Channel_Class_struct {
//	int (*sin_setup)(int speed, unsigned int sin_ID, unsigned int CS_ID,
//			Sin_Channel_Instance this);
//	int (*sin_read_analog)(Sin_Channel_Instance this);
//} Sin_Channel_Class;
//
//struct Sin_Channel_Instance_struct {
//	Sin_Channel_Class *clazz;
//	union ADC data;
//	int CS_ID;
//	int speed;
//	char *conf;
//	int sin_ID;
//};

typedef struct Diff_Channel_Instance_struct* Diff_Channel_Instance;
typedef struct Diff_Channel_Class_struct {
	int (*diff_setup)(int speed, unsigned int diff_ID, unsigned int CS_ID,
			Diff_Channel_Instance this);
	int (*diff_read_analog)(Diff_Channel_Instance this);
} Diff_Channel_Class;

struct Diff_Channel_Instance_struct {
	Diff_Channel_Class* clazz;
	union ADC data;
	int CS_ID;
	int speed;
	char *conf;
	int diff_ID;
};

int diff_setup(int speed, unsigned int diff_ID, unsigned int CS_ID,
		Diff_Channel_Instance this);
Diff_Channel_Instance newDiffChannel(int size);


int read_analog(Sin_Channel_Instance this);


Sin_Channel_Instance newSinChannel(int size);
int sin_setup(int speed, unsigned int sin_ID,unsigned int CS_ID,
		Sin_Channel_Instance this);


#endif /* MCP3204_H_ */
