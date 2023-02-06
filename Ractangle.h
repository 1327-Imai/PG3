#pragma once
#include "IShape.h"
class Ractangle : IShape {

public:
	Ractangle(float height,float width);
	~Ractangle();

	void Size()override;
	void Draw()override;

private:
	float height_;
	float width_;
	float surface_;
};

