#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES

#include <catch.hpp>
#include <numbers>

#include "Sphere.hpp"
#include "Box.hpp"

TEST_CASE("SPHERE AREA", "[sphere][area]")
{
    // Verify PI constant is correct (debug output)
    std::cout << "2*acos(0): " << 2 * acos(0.0) << std::endl;
    std::cout << "M_PI: " << M_PI << std::endl;

    // Test normal case
    SECTION("Normal values") {
        Sphere sphere(glm::vec3(0, 0, 0), 5.0);
        REQUIRE(sphere.area() == Approx(4 * M_PI * 25.0).margin(0.000001));
    }

    // Edge case: Minimal radius
    SECTION("Minimal radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 0.001);
        REQUIRE(sphere.area() == Approx(4 * M_PI * 0.000001).margin(0.000001));
    }

    // Edge case: Large radius
    SECTION("Large radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 1000.0);
        REQUIRE(sphere.area() == Approx(4 * M_PI * 1000000.0).margin(0.000001));
    }
}

TEST_CASE("SPHERE VOLUME", "[sphere][volume]")
{
    // Test normal case
    SECTION("Normal values") {
        Sphere sphere(glm::vec3(0, 0, 0), 5.0);
        REQUIRE(sphere.volume() == Approx((4.0 / 3.0) * M_PI * 125.0).margin(0.000001));
    }

    // Edge case: Minimal radius
    SECTION("Minimal radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 0.001);
        REQUIRE(sphere.volume() == Approx((4.0 / 3.0) * M_PI * 0.000000001).margin(0.000001));
    }

    // Edge case: Large radius
    SECTION("Large radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 1000.0);
        REQUIRE(sphere.volume() == Approx((4.0 / 3.0) * M_PI * 1000000000.0).margin(0.000001));
    }

    // Edge case: Negative radius (should throw exception)
}

TEST_CASE("BOX AREA", "[box][area]")
{
    // Test normal case
    SECTION("Normal values") {
        Box box(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1));
        REQUIRE(box.area() == Approx(24.0).margin(0.000001));
    }

    // Edge case: Minimal box
    SECTION("Minimal box") {
        Box box(glm::vec3(0, 0, 0), glm::vec3(0.001, 0.001, 0.001));
        REQUIRE(box.area() == Approx(6 * 0.001 * 0.001).margin(0.000001));
    }

    // Edge case: Large box
    SECTION("Large box") {
        Box box(glm::vec3(-1000, -1000, -1000), glm::vec3(1000, 1000, 1000));
        REQUIRE(box.area() == Approx(6 * 2000 * 2000).margin(0.000001));
    }
}

TEST_CASE("BOX VOLUME", "[box][volume]")
{
    // Test normal case
    SECTION("Normal values") {
        Box box(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1));
        REQUIRE(box.volume() == Approx(8.0).margin(0.000001));
    }

    // Edge case: Minimal box
    SECTION("Minimal box") {
        Box box(glm::vec3(0, 0, 0), glm::vec3(0.001, 0.001, 0.001));
        REQUIRE(box.volume() == Approx(0.001 * 0.001 * 0.001).margin(0.000001));
    }

    // Edge case: Large box
    SECTION("Large box") {
        Box box(glm::vec3(-1000, -1000, -1000), glm::vec3(1000, 1000, 1000));
        REQUIRE(box.volume() == Approx(2000.0 * 2000.0 * 2000.0).margin(0.000001));
    }
}

TEST_CASE("PrintShapes", "[Shape][Box][Sphere]") {
    SECTION("Box") {
        Box box1(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1));
        Box box2(glm::vec3(-1000, -1000, -1000), glm::vec3(1000, 1000, 1000), Color{ 1,1,1 }, std::string{ "Manfred" });
        std::cout << box1 << std::endl;
        std::cout << box2 << std::endl;
    }
    SECTION("Sphere") {
        Sphere sphere1(glm::vec3(0, 0, 0), 1000.0);
        Sphere sphere2(glm::vec3(0, 0, 0), 5.0, Color{ 1,0.5,1 }, std::string{ "Helga" });
        std::cout << sphere1 << std::endl;
        std::cout << sphere2 << std::endl;
    }

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
