/*
 * Shape.c
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#include "Shape.h"


void draw(Shape aShape){
	printf("\ndrawed shape\nx:%d\ny:%d\n",aShape->x,aShape->y);
	return;
}

void move(Shape aShape,int x,int y){
	printf("\nmoved shape\n");
	printf("from x:%d y:%d\n",aShape->x,aShape->y);
	aShape->x = x;
	aShape->y = y;
	printf("to x:%d y:%d\n",aShape->x,aShape->y);
}
