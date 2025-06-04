#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "Sphere.hpp"
#include "Box.hpp"

TEST_CASE("SPHERE AREA", "[sphere][area]")
{
    // Test normaler Fall
    SECTION("Normale Werte") {
        Sphere sphere(glm::vec3(0, 0, 0), 5.0);
        REQUIRE(sphere.area() == Approx(314.15926535897932384626433832795).margin(0.000001));
    }

    // Test Randfall: Minimaler Radius
    SECTION("Minimaler Radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 0.001);
        REQUIRE(sphere.area() == Approx(0.00031415926535897932384626433895).margin(0.000001));
    }

    // Test Randfall: Groﬂer Radius
    SECTION("Groﬂer Radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 1000.0);
        REQUIRE(sphere.area() == Approx(12566370614359175.0).margin(0.000001));
    }

    // Test Randfall: Negativer Radius (sollte Exception werfen)
    SECTION("Negativer Radius") {
        REQUIRE_THROWS_AS(Sphere(glm::vec3(0, 0, 0), -1.0), std::invalid_argument);
    }
}

TEST_CASE("SPHERE VOLUME", "[sphere][volume]")
{
    // Test normaler Fall
    SECTION("Normale Werte") {
        Sphere sphere(glm::vec3(0, 0, 0), 5.0);
        REQUIRE(sphere.volume() == Approx(523.59877559829887307710733865305).margin(0.000001));
    }

    // Test Randfall: Minimaler Radius
    SECTION("Minimaler Radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 0.001);
        REQUIRE(sphere.volume() == Approx(0.000004189184717016073079577471545).margin(0.000001));
    }

    // Test Randfall: Groﬂer Radius
    SECTION("Groﬂer Radius") {
        Sphere sphere(glm::vec3(0, 0, 0), 1000.0);
        REQUIRE(sphere.volume() == Approx(41887902047856684367486246923849.0).margin(0.000001));
    }

    // Test Randfall: Negativer Radius (sollte Exception werfen)
    SECTION("Negativer Radius") {
        REQUIRE_THROWS_AS(Sphere(glm::vec3(0, 0, 0), -1.0), std::invalid_argument);
    }
}

TEST_CASE("BOX AREA", "[box][area]")
{
    // Test normaler Fall
    SECTION("Normale Werte") {
        Box box(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1));
        REQUIRE(box.area() == Approx(24.0).margin(0.000001));
    }

    // Test Randfall: Minimaler Box
    SECTION("Minimaler Box") {
        Box box(glm::vec3(0, 0, 0), glm::vec3(0.001, 0.001, 0.001));
        REQUIRE(box.area() == Approx(0.000024).margin(0.000001));
    }

    // Test Randfall: Groﬂer Box
    SECTION("Groﬂer Box") {
        Box box(glm::vec3(-1000, -1000, -1000), glm::vec3(1000, 1000, 1000));
        REQUIRE(box.area() == Approx(48000000.0).margin(0.000001));
    }
}

TEST_CASE("BOX VOLUME", "[box][volume]")
{
    // Test normaler Fall
    SECTION("Normale Werte") {
        Box box(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1));
        REQUIRE(box.volume() == Approx(8.0).margin(0.000001));
    }

    // Test Randfall: Minimaler Box
    SECTION("Minimaler Box") {
        Box box(glm::vec3(0, 0, 0), glm::vec3(0.001, 0.001, 0.001));
        REQUIRE(box.volume() == Approx(0.000000000001).margin(0.000001));
    }

    // Test Randfall: Groﬂer Box
    SECTION("Groﬂer Box") {
        Box box(glm::vec3(-1000, -1000, -1000), glm::vec3(1000, 1000, 1000));
        REQUIRE(box.volume() == Approx(8000000000000.0).margin(0.000001));
    }
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
