#include "Shape.hpp"

Shape::Shape() {
	std::cout << "Shape Konstruktor\n";
}

Shape::Shape(Color colors, std::string names) {
	color_ = colors;
	name_ = names;
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
	return shape.print(os);
}

Shape::~Shape() {
	std::cout << "Shape Destruktor\n";
}

