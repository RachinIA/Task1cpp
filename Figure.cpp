#include "Figure.h"

Ellipse::Ellipse(double a, double b)
{
	if (a <= 0 || b <= 0)
		throw exception();
	first = a;
	second = b;
}

double Ellipse::getArea() const
{
	return M_PI * first * second;;
}

Circle::Circle(double rad)
{
	if (rad <= 0)
		throw exception();
	radius = rad;
}

double Circle::getArea() const
{
	return 2*M_PI*radius;
}
