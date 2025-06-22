#include "Box.hpp"

Box::Box(glm::vec3 c, glm::vec3 d) : Shape{}, min_{c}, max_{d} { 

}

Box::Box(glm::vec3 center, glm::vec3 d, Color co, std::string name)
	: Shape{ co, name }, min_{ center }, max_{ d } {
}

std::ostream& Box::print(std::ostream& os) const {
	os << "Box(min=(" << min_.x << ", " << min_.y << ", " << min_.z << "), max=(" << max_.x << ", " << max_.y << ", " << max_.z << ")"
		<< ", color=" << color_ << ", name=\"" << name_ << "\")";
	return os;
}

double Box::area() const {
	glm::vec3 difference = max_ - min_;
	return (std::abs(difference.x*difference.y) + std::abs(difference.x*difference.z) + std::abs(difference.y*difference.z))*2;
}

double Box::volume() const {
	glm::vec3 difference = max_ - min_;
	return std::abs(difference.x * difference.y * difference.z);
}