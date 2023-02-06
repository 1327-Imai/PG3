#pragma once
#include "IShape.h"
class Circle : IShape {
public:
	Circle(float radius);
	~Circle();

	void Size()override;
	void Draw()override;

private:
	float surface_;
	float radius_;
};

