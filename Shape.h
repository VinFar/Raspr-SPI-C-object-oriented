/*
 * header.h
 *
 *  Created on: 23.10.2017
 *      Author: ak534552
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <stdlib.h>
#include <stdio.h>
#include "CObjects.h"




BEG_DEFINE_CLASS(Shape)
Shape_METHODS
END_DEFINE_CLASS(Shape)


BEG_DEFINE_INSTANCE(Shape)
Shape_ATTRIBUTES
END_DEFINE_INSTANCE(Shape)

void draw(Shape aShape);
void move(Shape aShape,int x,int y);

#endif /* SHAPE_H_ */

