#include "Circle.h"
#include <stdio.h>
#include <math.h>

Circle::Circle(float radius) {

	radius_ = radius;

	Size();

}

Circle::~Circle() {

}

void Circle::Size() {

	surface_ = pow(radius_ , 2) * 3.141592;

}

void Circle::Draw() {

	printf("Ç±ÇÃâ~ÇÃñ êœÇÕ%f\n",surface_);

}