/*
 * Rect.h
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#ifndef RECT_H_
#define RECT_H_
#include "MCP3204.h"
#include "Shape.h"

#if SPI_Debug
#else
DEFINE_EXTENDED_TYPE(Rect,Shape)



Rect newRect(int x, int y, int w, int h);
void rotate(Shape ashape,int angle);
#endif
#endif /* RECT_H_ */
