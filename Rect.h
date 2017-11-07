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



Rect newRect(int x, int y, int w, int h);
void rotate(Shape ashape,int angle);

#endif /* RECT_H_ */
