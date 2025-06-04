#include <iostream>

class Shape {
public:
	virtual double area() const = 0;
	virtual double volume() const = 0;
	virtual ~Shape() {}
};