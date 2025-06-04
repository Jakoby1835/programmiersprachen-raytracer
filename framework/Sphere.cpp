#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(glm::vec3 c, double r) : Shape{}, center_{ c }, radius_{ r } {
	
}

double Sphere::area() const {
	return 8*std::acos(0)*radius_*radius_;
}

double Sphere::volume() const {
	return (8.0 / 3.0) * std::acos(0) * radius_ * radius_ * radius_;
}