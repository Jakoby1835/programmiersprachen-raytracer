#pragma once
#include <iostream>
#include "color.hpp"

class Shape {
protected:
	std::string name_ = "";
	Color color_ = { 1,1,1 };
public:
	

	Shape();
	Shape(Color colors, std::string names);

	virtual std::ostream& print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Shape& shape);

	virtual double area() const = 0;
	virtual double volume() const = 0; //wenn = 0, ust rein virtuell, wenn nicht dannn nur virtuell
	virtual ~Shape();
};
