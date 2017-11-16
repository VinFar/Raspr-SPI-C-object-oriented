/*
 * Rect.h
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */


#include "Rect.h"
#include "MCP3204.h"
#if SPI_Debug
#else
static ShapeClass shapeclass = {&draw,&move};

void rotate(Shape ashape,int angle){

	printf("rotated: %d",angle);

	return;
}

Rect newRect(int x, int y, int w,int h){
	Rect shape;

	shape = malloc(sizeof(Rect));
	shape->x = x;
	shape->y = y;
	shape->w = w;
	shape->h = h;
	shape->clazz = &shapeclass;

	return shape;
}
#endif
