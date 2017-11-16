/*
 * Circle.h
 *
 *  Created on: 03.11.2017
 *      Author: vincent
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_


#include "Shape.h"
#include "MCP3204.h"

#if SPI_Debug
#else
BEG_DEFINE_CLASS(Circle) EXTENDS(Shape)
METHODS(Circle)
END_DEFINE_CLASS(Circle)

BEG_DEFINE_INSTANCE(Circle) INSTANCE_OF(Shape)
ATTRIBUTES(Circle)
END_DEFINE_INSTANCE()

Circle newCircle(int x, int y, int r);
#endif

#endif /* CIRCLE_H_ */
