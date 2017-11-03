/*
 * Shape.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#include "Shape.h"


void draw(Shape aShape){
	printf("Shape:%d",aShape->x);
	return;
}

void move(Shape aShape){
	printf("move Shape");
}
