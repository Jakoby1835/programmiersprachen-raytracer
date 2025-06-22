#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES

#include <catch.hpp>
#include <numbers>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

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
    /*    Virtuelle Funktionen:
    virtual in der Basis - Klasse ermöglicht Überschreibung
        = 0 macht die Funktion rein virtuell
        Ermöglicht polymorphes Verhalten bei Laufzeit
        Override - Schlüsselwort:
    Garantiert korrekte Überschreibung der virtuellen Funktion
        Verhindert Fehler bei der Signatur
        Macht die Überschreibung explizit im Code sichtbar
        Stream - Operator :
        Ermöglicht einfache Ausgabe mit <<
        Nutzt die virtuelle print() - Methode
        Funktioniert mit allen abgeleiteten Klassen
        Vererbungshierarchie :
    Shape als abstrakte Basis - Klasse
        Box und Sphere als konkrete abgeleitete Klassen
        Jede abgeleitete Klasse implementiert ihre eigene print() - Methode*/
}

TEST_CASE("intersect_ray_sphere", "[intersect]")
{
    // Ray
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
    // ray direction has to be normalized !
    // you can use:
    // v = glm::normalize(some_vector)
    glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
    // Sphere
    glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
    float sphere_radius{ 1.0f };
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction,
        sphere_center,
        sphere_radius * sphere_radius, // squared radius !!!
        distance);
    REQUIRE(distance == Approx(4.0f));
}

/*Die Typbeziehungen in diesem Beispiel können wie folgt erklärt werden :

Statischer Typ :
Wird zur Compile - Zeit festgelegt
Ist der deklarierte Typ der Variablen
Kann nicht geändert werden
Dynamischer Typ :
Ist der tatsächliche Typ des Objekts
Wird zur Laufzeit bestimmt
Kann sich von dem statischen Typ unterscheiden

Für die Variablen s1 und s2 gilt:

    s1:
        Statischer Typ: std::shared_ptr<Sphere>
        Dynamischer Typ: Sphere
        Die Typen stimmen überein
    s2:
        Statischer Typ: std::shared_ptr<Shape>
        Dynamischer Typ: Sphere
        Nutzt Polymorphismus durch Vererbung

Die Typ-Überprüfung erfolgt zu unterschiedlichen Zeitpunkten:

    Compile-Time:
        Überprüfung der statischen Typen
        Kontrolle der Pointer-Operationen
        Validierung der Vererbungsbeziehungen
    Runtime:
        Bestimmung der dynamischen Typen
        Auflösung virtueller Funktionsaufrufe
        Typ-Überprüfung bei dynamischer Typbestimmung

Diese Struktur ermöglicht es, Objekte polymorph zu behandeln, während die Typsicherheit durch die Compile-Time-Überprüfung gewährleistet bleibt.*/

TEST_CASE("5.8", "[TEST_PROGRAMM]") {
    std::cout << "\n\n";
    Color red{ 255, 0, 0 };
    glm::vec3 position{ 0.0f, 0.0f, 0.0f };
    Sphere* s1 = new Sphere{ position, 1.2f, red, "sphere0" };
    Shape* s2 = new Sphere{ position, 1.2f, red, "sphere1" };
    s1->print(std::cout);
    s2->print(std::cout);
    delete s1;
    delete s2;
}
/*    Konstruktorenaufrufe:
        Zuerst wird der Shape-Konstruktor aufgerufen (Base-Klasse)
        Dann wird der Sphere-Konstruktor aufgerufen (Derived-Klasse)
        Dieser Prozess wiederholt sich für beide Sphären
    Print-Ausgabe:
        Die Ausgabe zeigt die korrekten Eigenschaften beider Sphären
        Position: (0, 0, 0)
        Radius: 1.2
        Farbe: (255,0,0) = Rot
        Namen: "sphere0" und "sphere1"
    Destruktorenaufrufe:
        Die Shape-Destruktoren werden aufgerufen
        Dies ist korrekt, da die virtuelle Destruktor-Methode implementiert wurde
        Die Sphere-Destruktoren werden automatisch vor den Shape-Destruktoren aufgerufen

Die Ausgabe bestätigt, dass:

    Die Vererbungshierarchie korrekt funktioniert
    Die Konstruktoren in der richtigen Reihenfolge aufgerufen werden
    Die Destruktoren korrekt durch den virtuellen Destruktor der Shape-Klasse aufgerufen werden
    Alle Eigenschaften der Sphären korrekt gespeichert und ausgegeben werden*/

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
