/*
 * CObjects.h
 *
 *  Created on: 03.11.2017
 *      Author: vincent
 */

#ifndef COBJECTS_H_
#define COBJECTS_H_


/*define header of class*/
#define BEG_DEFINE_CLASS(T) typedef struct T##_Instance_struct* T; \
	typedef struct T##_Class_struct {

/*define end of class */
#define END_DEFINE_CLASS(T) } T##Class;

/*extend for shape*/
#define EXTENDS(T)	SHAPE_METHODS(T)



/*define header of instance */
#define BEG_DEFINE_INSTANCE(T) typedef struct T##_Instance_struct {

/*define end of instance*/
#define END_DEFINE_INSTANCE(T) } T##Instance;

/*instance of for shape*/
#define INSTANCE_OF(T) SHAPE_ATTRIBUTES(T)



#define DEFINE_EXTENDED_TYPE(T,E)	BEG_DEFINE_CLASS(T) EXTENDS(E)\
									Rect_METHODS(T##class)\
									END_DEFINE_CLASS(T)\
									\
									BEG_DEFINE_INSTANCE(T) INSTANCE_OF(E)\
									Rect_ATTRIBUTES \
									END_DEFINE_INSTANCE(T)

/*
 *
 * Shape defines
 *
 */
/*define for shape methdo*/
#define SHAPE_METHODS(T)	void (*draw)(Shape T); \
							void (*move)(Shape T,int x,int y);

/*define for Shape attributes*/
#define SHAPE_ATTRIBUTES(T)	T##Class* clazz;\
							int x;\
							int y;



/*
 *
 * Circle defines
 *
 */

#define Circle_METHODS(T) void (*resize)(Circle T, int r);

#define Circle_ATTRIBUTES int r;

/*
 *
 * Rectangle defines
 *
 */

/*define Rect methods*/
#define Rect_METHODS(T) void (*resize)(Rect T, int w, int h);

/*define Rect Attributes*/
#define Rect_ATTRIBUTES int w;\
						int h;






#endif /* COBJECTS_H_ */
