#include <stdio.h>
#include "Circle.h"
#include "Ractangle.h"

int main() {

	Circle* circle = new Circle(5.0f);
	Ractangle* ractangle = new Ractangle(2.0f , 3.0f);

	circle->Draw();
	ractangle->Draw();

	delete circle;
	delete ractangle;

	return 0;
}