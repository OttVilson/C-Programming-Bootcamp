#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory>

class Pizza {
    public:
        virtual void MakePizza() = 0;
};

class ThickBase {
    public:
        std::string AddIngredient() {
            return "Thick base";
        }
};

class ThinBase {
    public:
        std::string AddIngredient() {
            return "Thin base";
        }
};

template<typename T>
class Meat: public T {
    public:
        std::string AddIngredient() {
            return "Lots of meat, and " + T::AddIngredient();
        }
};

template<typename T>
class Vege: public T {
    public:
        std::string AddIngredient() {
            return "Lots of vegetables, and " + T::AddIngredient();
        }
};

template<typename T>
class PizzaType: public Pizza, public T {
    public:
        void MakePizza() override {
            std::cout << "Make pizza by making use of : " << T::AddIngredient() << "\n";
        }
};

int main() {

    std::vector<std::unique_ptr<Pizza>> pizzaOrders;
    pizzaOrders.emplace_back(new PizzaType<Vege<ThickBase>>());
    pizzaOrders.emplace_back(new PizzaType<Meat<ThickBase>>());
    pizzaOrders.emplace_back(new PizzaType<Vege<ThinBase>>());
    pizzaOrders.emplace_back(new PizzaType<Meat<ThinBase>>());

    for (std::unique_ptr<Pizza> &pizza : pizzaOrders) {
        pizza->MakePizza();
    }


    return 0;
}