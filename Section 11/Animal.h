#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
    private:
        std::string name;
    public:
        Animal(std::string name);
        std::string GetName();
};

#endif