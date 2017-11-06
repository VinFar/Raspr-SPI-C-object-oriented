/*
 * Rect.h
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#ifndef RECT_H_
#define RECT_H_

#include "Shape.h"


DEFINE_EXTENDED_TYPE(Rect,Shape)

BEG_DEFINE_CLASS(Rect) EXTENDS(Shape)
Rect_METHODS
END_DEFINE_CLASS(Rect)

BEG_DEFINE_INSTANCE(Rect) INSTANCE_OF(Shape)
Rect_ATTRIBUTES
END_DEFINE_INSTANCE(Rect)



Rect newRect(int x, int y, int w, int h);
void rotate(Shape ashape,int angle);

#endif /* RECT_H_ */
