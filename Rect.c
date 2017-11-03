/*
 * Rect.h
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */


#include "Rect.h"


static void draw(Shape rect){

	printf("\ndraw rect \n w:%d",rect->x);
	return;
}

static void move(Shape rect,int x,int y){

	rect->x=x;
	rect->y=y;
	printf("rect moved\n x:%d\n y:%d",rect->x,rect->y);
	return;
}

static ShapeClass shapeclass = {&draw,&move};

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
