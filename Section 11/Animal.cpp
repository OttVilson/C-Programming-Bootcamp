#include "Animal.h"

Animal::Animal(std::string name) {
    this->name = name;
}

std::string Animal::GetName() {
    return name;
}