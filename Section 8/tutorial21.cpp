#include <cstdlib>
#include <iostream>
#include <cmath>

double Area(double radius);
void Area(double width, double height);

int main() {
    std::cout << "Do you want to calculate the area of a Circle (c) or Rectangle (r) : ";
    char areaType;
    std::cin >> areaType;

    switch (areaType) {
    case 'r':
        double width; double height;
        std::cout << "Enter width : ";
        std::cin >> width;
        std::cout << "Enter height : ";
        std::cin >> height;
        Area(width, height);
        break;
    case 'c':
        double radius;
        std::cout << "Enter radius : ";
        std::cin >> radius;
        std::cout << "The area is " << Area(radius) << "\n";
        break;
    default:
        std::cout << "Next time enter r or c.\n";
        break;
    } 

    return 0;
}

double Area(double radius) {
    return 3.1415 * pow(radius, 2);
}

void Area(double width, double height) {
    printf("Area with width %.1f and height %.1f is %.1f.\n", width, height, width * height);
}
