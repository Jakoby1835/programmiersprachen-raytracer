#include <iostream>
#include "Shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape{
private:
	glm::vec3 center_;
	double radius_;
public:
	Sphere(glm::vec3 c, double r);
	Sphere(glm::vec3 c, double r, Color co, std::string name);
	std::ostream& print(std::ostream& os) const override;
	double area() const override;
	double volume() const override;
};