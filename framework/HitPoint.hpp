#include <iostream>
#include <glm/vec3.hpp>

#include "color.hpp"

struct HitPoint {
    bool hit = false;
    float distance = 0.0f;
    std::string name;
    Color color;
    glm::vec3 point;
    glm::vec3 direction;
};