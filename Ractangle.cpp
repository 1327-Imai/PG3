#include "Ractangle.h"
#include <stdio.h>

Ractangle::Ractangle(float height , float width) {

	height_ = height;
	width_ = width;

	Size();

}

Ractangle::~Ractangle() {

}

void Ractangle::Size() {

	surface_ = height_ * width_;

}

void Ractangle::Draw() {

	printf("この矩形の面積は%f\n" , surface_);

}