#include <iostream>
#include "Shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape{
private:
	glm::vec3 center_;
	double radius_;
public:
	double area() const override;
	double volume() const override;
};