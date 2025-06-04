#include "Box.hpp"

Box::Box(glm::vec3 c, glm::vec3 d) : Shape{}, min_{c}, max_{d} { 

}

double Box::area() const {
	glm::vec3 difference = max_ - min_;
	return ((difference.x*difference.y) + (difference.x*difference.z) + (difference.y*difference.z))*2;
}

double Box::volume() const {
	glm::vec3 difference = max_ - min_;
	return difference.x * difference.y * difference.z;
}