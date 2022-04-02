#include <cstdlib>
#include <iostream>

class Animal {
    private:
        std::string name;
        double height;
        double weight;

        static int numOfAnimals;
    
    public:
        std::string GetName() {
            return name;
        }

        void SetName(std::string name) {
            this->name = name;
        }

        void SetAll(std::string, double, double);

        Animal(std::string, double, double);
        ~Animal();

        static int GetNumOfAnimals() {
            return numOfAnimals;
        }

        std::string ToString() {
            return "The animal " + name + " has height " + std::to_string(height) + " and weight " 
                + std::to_string(weight) + ".";
        }
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight) {
    this->name = name;
    this->height = height;
    this->weight = weight;
}

Animal::Animal(std::string name, double height, double weight) {
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++;
}

Animal::~Animal() {
    std::cout << "The animal " << name << " destroyed.\n";
    Animal::numOfAnimals--;
}

int main() {
    std::cout << Animal::GetNumOfAnimals() << "\n";
    Animal animal ("Mart", 20.0, 15.0);
    std::cout << Animal::GetNumOfAnimals() << "\n";
    std::cout << animal.GetNumOfAnimals() << "\n";
    std::cout << animal.ToString() << "\n";
    animal.~Animal();
    std::cout << Animal::GetNumOfAnimals() << "\n";

    return 0;
}