#include <iostream>
#include <glm/vec3.hpp>

#include "Shape.hpp"
#include "HitPoint.hpp"
#include "Ray.hpp"

class Sphere : public Shape{
private:
	glm::vec3 center_;
	double radius_;
public:
	Sphere(glm::vec3 c, double r);
	Sphere(glm::vec3 c, double r, Color co, std::string name);
	std::ostream& print(std::ostream& os) const override;
	HitPoint Sphere::intersect(const Ray& ray) const;
	double area() const override;
	double volume() const override;
};