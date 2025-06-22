#include "Shape.hpp"
#include <iostream>
#include <glm/vec3.hpp>

class Box : public Shape{
private:
	glm::vec3 min_;
	glm::vec3 max_;
public:
	Box(glm::vec3 min, glm::vec3 max);
	Box(glm::vec3 min, glm::vec3 d, Color co, std::string name);
	double area() const override;
	double volume() const override;

};