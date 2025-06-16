#pragma once
#include <iostream>
#include "color.hpp"

class Shape {
private:
	std::string name_ = "";
	Color color_ = {1,1,1};
public:
	Shape();
	Shape(Color colors, std::string names);
	virtual double area() const = 0;
	virtual double volume() const = 0; //wenn = 0, ust rein virtuell, wenn nicht dannn nur virtuell
	virtual ~Shape();
};
