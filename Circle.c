/*
 * Circle.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#include "Circle.h"

/*singleton*/
static ShapeClass circle_class = {draw,&move};


Circle newCircle(int x, int y, int r){
	Circle shape;

	shape = alloc(Circle);
/*	shape = malloc(sizeof(struct Circle_Instance_struct));*/

	shape->x = x;
	shape->y = y;
	shape->r = r;

	shape->clazz = &circle_class;

	return shape;
}
