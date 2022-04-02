#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

class Shape {
    public:
        virtual double Area() {};
};

class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle(double width, double height) {
            this->width = width;
            this->height = height;
        }

        double Area() {
            return width*height;
        }
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double radius) {
            this->radius = radius;
        }

        double Area() {
            return 3.1415 * pow(radius, 2);
        }
};

void PrintArea(Shape& shape) {
    std::cout << shape.Area() << "\n";
}

int main() {
    Rectangle rectangle (2, 5);
    Circle circle (10);

    std::vector<Shape*> shapes;
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    for (Shape* s : shapes)
        std::cout << s->Area() << "\n";

    std::cout << "Rectangle\n";
    PrintArea(rectangle);
    std::cout << "Circle\n";
    PrintArea(circle);
    return 0;
}