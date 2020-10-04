#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Curve 
{
public:
	virtual double getArea() const = 0;  //Get area of figure
};

class Ellipse : public Curve
{
public:
	Ellipse(double a, double b);
	double getArea(double first, double second);
	~Ellipse() = default;
private:
	double first, second;
};

class Circle : public Curve
{
	Circle(double rad);
	double getArea(double rad);
	~Circle() = default;
private:
	double radius;
};