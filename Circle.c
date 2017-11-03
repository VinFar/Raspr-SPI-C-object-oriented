/*
 * Circle.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#include "Circle.h"

static void draw(Shape circle){

	printf("draw x:%d",circle->x);
	return;
}

static void move(Shape circle,int x,int y){

	circle->x=x;
	circle->y=y;
	printf("moved circle \n x:%d\n y:%d",circle->x,circle->y);
	return;
}

/*singleton*/
static ShapeClass circle_class = {&draw,&move};

Circle newCircle(int x, int y, int r){
	Circle shape;

	shape = alloc(Circle);
//	shape = malloc(sizeof(struct Circle_Instance_struct));

	shape->x = x;
	shape->y = y;
	shape->r = r;

	shape->clazz = &circle_class;

	return shape;
}
