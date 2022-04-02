#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

class Box {
    private:
        double width, height, breadth;
        std::string boxString;
    public:
        Box(double width = 1, double height = 1, double breadth = 1) {
            this->width = width;
            this->height = height;
            this->breadth = breadth;
        }
        Box& operator ++ () {
            width++;
            height++;
            breadth++;
            return *this;
        }

        operator const char*() {
            std::ostringstream boxStream;
            boxStream << "Box : width " << width << 
                ", height " << height << 
                ", breadth " << breadth;
            
            boxString = boxStream.str();
            return boxString.c_str();
        }

        Box operator + (const Box& other) {
            Box box(width + other.width, height + other.height, breadth + other.breadth);
            return box;
        }

        double operator [] (int n) {
            double value;
            switch(n) {
                case 0:
                    value = width;
                    break;
                case 1:
                    value = height;
                    break;
                case 2:
                    value = breadth;
                    break;
                default:
                    throw std::runtime_error("No such index.");
            }
            return value;
        }

        bool operator == (const Box& other) {
            return width == other.width &&
                    height == other.height &&
                    breadth == other.breadth;
        }
};

void Increase(Box& box) {
    ++box;
}

int main() {
    Box box;
    std::cout << box << std::endl;
    Increase(++box);
    std::cout << box << std::endl;

    Box* box1Ptr = &++box;
    ++box;
    std::cout << box << std::endl;
    std::cout << *box1Ptr << std::endl;

    Box first(13, 15, 17);
    Box other(13, 15, 17);
    std::cout << first + other << std::endl; 

    
    std::cout << "first and other are equal? " << std::to_string(first == other) << "\n";
    ++first; 
    std::cout << "first and other are equal? " << std::to_string(first == other) << "\n";

    try {
        std::cout << "[0]: " << other[0] << "; [1]: " << other[1] << "; [2]: " << other[2] << "\n";
    } catch(std::exception& exception) {
        std::cout << exception.what() << "\n";
    }

    return 0;
}