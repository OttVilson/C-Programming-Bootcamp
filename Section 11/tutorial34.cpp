#include <cstdlib>
#include <iostream>
#include "Animal.h"

#define OTT 3.1313
#define AREA_CIRCLE(radius) (PI * (pow(radius, 2)))

#define ERLE(name) (name "Ott" name)

int main() {
    Animal animal ("Ott");
    std::cout << animal.GetName() << "\n";

    std::cout << ERLE("Erle") << "\n";
    std::cout << OTT << "\n";
    return 0;
}