/*
 * Circle.h
 *
 *  Created on: 03.11.2017
 *      Author: vincent
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_


#include "Shape.h"

BEG_DEFINE_CLASS(Circle) EXTENDS(Shape)
Circle_METHODS
END_DEFINE_CLASS(Circle)

BEG_DEFINE_INSTANCE(Circle) INSTANCE_OF(Shape)
Circle_ATTRIBUTES
END_DEFINE_INSTANCE()

Circle newCircle(int x, int y, int r);


#endif /* CIRCLE_H_ */
