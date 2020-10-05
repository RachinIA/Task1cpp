#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Curve 
{
public:
	virtual double getArea() const = 0; 
	virtual ~Curve() = default;
};

class Ellipse : public Curve
{
public:
	Ellipse(double a, double b);
	double getArea() const override;
	~Ellipse() = default;
private:
	double first, second;
};

class Circle : public Curve
{
public:
	Circle(double rad);
	double getArea() const override;
	~Circle() = default;
private:
	double radius;
};