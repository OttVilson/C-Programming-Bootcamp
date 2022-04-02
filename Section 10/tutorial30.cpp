#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

class Shape {
    public:
        virtual double Area() = 0;
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double radius) {
            this->radius = radius;
        }
        double Area() override {
            return 3.1415 * pow(radius, 2);
        }
};

class Rectangle : public Shape {
    private:
        double height;
        double width;
    public:
        Rectangle(double height, double width) {
            this->height = height;
            this->width = width;
        }
        double Area() override final {
            return height * width;
        }
};

class Square : public Rectangle {
    public:
        Square(double edge) : Rectangle(edge, edge) {}
};

void ShowArea(Shape& shape) {
    std::cout << shape.Area() << std::endl;
}

int main() {
    Rectangle rectangle (10, 5);
    Square square (5);
    Circle circle (10);

    ShowArea(rectangle);
    ShowArea(square);
    ShowArea(circle);

    std::vector<Shape*> shapes;
    shapes.push_back(&rectangle);
    shapes.push_back(&square);
    shapes.push_back(&circle);

    for (Shape* s : shapes)
        std::cout << s -> Area() << "\n";

    return 0;
}