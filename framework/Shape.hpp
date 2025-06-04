#include <iostream>

class Shape {
public:
	Shape();
	virtual double area() const = 0;
	virtual double volume() const = 0; //wenn = 0, ust rein virtuell, wenn nicht dannn nur virtuell
	virtual ~Shape();
};
