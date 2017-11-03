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
SHAPE_METHODS(shape)
END_DEFINE_CLASS(Shape)


BEG_DEFINE_INSTANCE(Shape)
SHAPE_ATTRIBUTES(Shape)
END_DEFINE_INSTANCE(Shape)


#endif /* SHAPE_H_ */

