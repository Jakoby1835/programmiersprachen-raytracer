#include "Sphere.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>

Sphere::Sphere(glm::vec3 c, double r) : Shape{}, center_{ c }, radius_{ r } {
	
}
Sphere::Sphere(glm::vec3 c, double r, Color co, std::string name) : Shape{co,name}, center_{ c }, radius_{ r } {

}

std::ostream& Sphere::print(std::ostream& os) const {
	os << "Box(center=(" << center_.x << ", " << center_.y << ", " << center_.z << "), radius=" << radius_
		<< ", color=" << color_ << ", name=\"" << name_ << "\")";
	return os;
}

HitPoint Sphere::intersect(const Ray& ray) const {
    HitPoint hit;

    // Normalisierung der Strahlrichtung
    glm::vec3 normalized_direction = glm::normalize(ray.direction);

    // Berechnung des Schnittpunkts
    float distance = 0.0f;
    bool result = glm::intersectRaySphere(
        ray.origin,
        normalized_direction,
        center_,
        radius_ * radius_,  // quadrierter Radius
        distance
    );

    // Füllen des HitPoint-Objekts bei Schnitt
    if (result) {
        hit.hit = true;
        hit.distance = distance;
        hit.name = name_;
        hit.color = color_;
        hit.point = ray.origin + distance * normalized_direction;
        hit.direction = normalized_direction;
    }

    return hit;
}

double Sphere::area() const {
	return std::abs(8*std::acos(0)*radius_*radius_);
}

double Sphere::volume() const {
	return std::abs((8.0 / 3.0) * std::acos(0) * radius_ * radius_ * radius_);
}