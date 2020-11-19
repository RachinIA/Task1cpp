#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Curve 
{
public:
	virtual void accept(class Visitor &v) = 0;
	virtual double getArea() const = 0; 
	virtual ~Curve() = default;
};

class Ellipse : public Curve
{
public:
	Ellipse(double a, double b);
	double getArea() const override;
	void accept(Visitor& visitor) override;
	~Ellipse() = default;
private:
	double first, second;
};

class Circle : public Curve
{
public:
	Circle(double rad);
	double getArea() const override;
	void accept(Visitor& visitor) override;
	~Circle() = default;
private:
	double radius;
};

class Visitor {
public:
	virtual void visit(Ellipse& ref) = 0;
	virtual void visit(Circle& ref) = 0;
	virtual ~Visitor() = default;
};

class GetArea : public Visitor {
public:
	double value;

public:
	void visit(Ellipse& ref) override {
		value = ref.getArea();
	}
	void visit(Circle& ref) override {
		value = ref.getArea();
	}
};
