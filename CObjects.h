/*
 * CObjects.h
 *
 *  Created on: 03.11.2017
 *      Author: vincent
 */

#ifndef COBJECTS_H_
#define COBJECTS_H_

typedef unsigned bool;

/*easier type-safe malloc*/
#define alloc(T) (T)malloc(sizeof(struct T##_Instance_struct))

/*define header of class*/
#define BEG_DEFINE_CLASS(T) typedef struct T##_Instance_struct* T; \
	typedef struct T##_Class_struct {

/*define end of class */
#define END_DEFINE_CLASS(T) } T##Class;

/*extend for shape*/
#define EXTENDS(T)	T##_METHODS



/*define header of instance */
#define BEG_DEFINE_INSTANCE(T) typedef struct T##_Instance_struct {

/*define end of instance*/
#define END_DEFINE_INSTANCE(T) } T##Instance;

/*instance of for shape*/
#define INSTANCE_OF(T) T##_ATTRIBUTES

#define METHODS(T) T##_METHODS

#define ATTRIBUTES(T) T##_ATTRIBUTES



/*define class with extends and instance of*/
#define DEFINE_EXTENDED_TYPE(T,E)	BEG_DEFINE_CLASS(T) EXTENDS(E)\
									T##_METHODS\
									END_DEFINE_CLASS(T)\
									\
									BEG_DEFINE_INSTANCE(T) INSTANCE_OF(E)\
									T##_ATTRIBUTES \
									END_DEFINE_INSTANCE(T)


#define DEFINE_BASE_TYPE(T) BEG_DEFINE_CLASS(T) \
							T##_METHODS \
							END_DEFINE_CLASS(T)\
							\
							BEG_DEFINE_INSTANCE(T) \
							T##_ATTRIBUTES \
							END_DEFINE_INSTANCE(T)



/*
 *
 * Shape defines
 *
 */
/*define for shape methdo*/
#define Shape_METHODS		void (*draw)(Shape ashape); \
							void (*move)(Shape ashape,int x,int y);

/*define for Shape attributes*/
#define Shape_ATTRIBUTES	ShapeClass* clazz;\
							int x;\
							int y;



/*
 *
 * Circle defines
 *
 */

#define Circle_METHODS void (*resize)(Circle acircle, int r);

#define Circle_ATTRIBUTES int r;

/*
 *
 * Rectangle defines
 *
 */

/*define Rect methods*/
#define Rect_METHODS	void (*resize)(Rect arect, int w, int h); \
						void (*rotate)(Rect arect,int anlge);

/*define Rect Attributes*/
#define Rect_ATTRIBUTES int w;\
						int h;

#define Led_ATTRIBUTES	int GPIO; \
						bool status;

#define Led_METHODS	void (*on)(Led aled); \
					void (*off)(Led aled); \
					bool (*getStatus)(Led aled);

#define PWMLed_ATTRIBUTES int value;

#define PWMLed_METHODS




#endif /* COBJECTS_H_ */
