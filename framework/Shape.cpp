#include "Shape.hpp"

Shape::Shape() {

}

Shape::Shape(Color colors, std::string names) {
	color_ = colors;
	name_ = names;
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
	return shape.print(os);
}

Shape::~Shape() {

}

