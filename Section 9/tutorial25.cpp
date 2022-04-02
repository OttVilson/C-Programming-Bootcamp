#include <cstdlib>
#include <iostream>

class Animal {
    private: 
        std::string name;

        static int numberOfAnimals;

    public:
        Animal(std::string name);
        ~Animal();
        std::string GetName();
        std::string ToString();

        static int GetNumberOfAnimals();
};

int Animal::numberOfAnimals = 0;

Animal::Animal(std::string name) {
    this->name = name;
    Animal::numberOfAnimals++;
}

Animal::~Animal() {
    Animal::numberOfAnimals--;
    std::cout << "Destroyed animal " << this->ToString() << "\n";
}

std::string Animal::GetName() {
    return name;
}

std::string Animal::ToString() {
    return "The animal " + name + ".";
}

int Animal::GetNumberOfAnimals() {
    return Animal::numberOfAnimals;
}

class Dog: public Animal {
    private:
        std::string sound;

    public:
        Dog(std::string name, std::string sound = "woooof"): Animal(name){
            this->sound = sound;
        };
        void MakeSound() {
            std::cout << "The dog " << this->GetName() << " says " << sound << ".\n";
        }
        std::string ToString() {
            return "The dog " + this->GetName() + " does the sound " + sound;
        }
};

int main() {
    std::cout << Animal::GetNumberOfAnimals() << "\n";
    Animal animal ("Rex");
    Dog tom ("Tom", "Ahahhahha");
    tom.MakeSound();

    std::cout << animal.ToString() << "\n";
    std::cout << tom.ToString() << "\n";
    std::cout << Animal::GetNumberOfAnimals() << "\n";

    return 0;
}