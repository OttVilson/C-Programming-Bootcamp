#include <iostream>

struct Shape {
    double length, width;

    Shape(double length = 1, double width = 1) {
        this->length = length;
        this->width = width;
    }

    double Area() {
        return length * width;
    }

    private:
        int id;
};

struct Circle : Shape {
    Circle(double length, double width): Shape(length, width) {}
};

int main() {

    Circle circle = Circle{2, 5};
    std::cout << circle.Area() << "\n";
}
