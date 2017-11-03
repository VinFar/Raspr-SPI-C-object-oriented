/*
 * Circle.h
 *
 *  Created on: 03.11.2017
 *      Author: vincent
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_


#include "Shape.h"

//typedef struct Circle_Instance_struct* CircleInstance;
//typedef struct circle_Class{
//	void (*draw)(CircleInstance circle );
//	void (*move)(CircleInstance circle,int x,int y);
//}CircleClass;
//
//
//struct Circle_Instance_struct{
//	CircleClass* clazz;
//	int x;
//	int y;
//	int r;
//};



BEG_DEFINE_CLASS(Circle) EXTENDS(SHAPE)
Circle_METHODS
END_DEFINE_CLASS(Circle)

BEG_DEFINE_INSTANCE(Circle) INSTANCE_OF(SHAPE)
Circle_ATTRIBUTES
END_DEFINE_INSTANCE()

Circle newCircle(int x, int y, int r);


#endif /* CIRCLE_H_ */
