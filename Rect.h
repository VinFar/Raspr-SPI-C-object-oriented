/*
 * Rect.h
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#ifndef RECT_H_
#define RECT_H_

#include "Shape.h"

//typedef struct Rect_Instance* Rect;
//

//
//typedef struct rect_Class {
//	void (*draw)(Rect rect);
//	void (*move)(Rect rect, int x, int y);
//} RectClass;
//
//struct Rect_Instance {
//	RectClass* clazz;
//	int x;
//	int y;
//	int w;
//	int h;
//};

DEFINE_EXTENDED_TYPE(Rect,Shape)



Rect newRect(int x, int y, int w, int h);


#endif /* RECT_H_ */
