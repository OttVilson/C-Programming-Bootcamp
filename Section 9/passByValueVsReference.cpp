#include <iostream>

class Warrior {
    private:
        int value;
    public:
        Warrior(int value) {
            this->value = value;
        }
        
        int GetValue() {
            return value;
        }

        void SetValue(int value) {
            this->value = value;
        }

        void PrintValue() {
            std::cout << "Value is " << value << ", and its memory location is " << &value << ".\n";
        }
};

// https://stackoverflow.com/questions/49097505/passing-an-object-by-reference-and-storing-it-as-a-member-variable
class WarriorWrapper {
    private:
        Warrior& warrior;
    public:
        WarriorWrapper(Warrior& warrior) : warrior(warrior) {}

        void Print() {
            std::cout << "The memory location of the warrior is " << &warrior << "\n";
            warrior.PrintValue();
        }

        void SetValue(int value) {
            warrior.SetValue(value);            
        }
};

void PassByValue(Warrior copy) {
    // Warrior copy = warrior;

    copy.SetValue(10);
    copy.PrintValue();
}

void PassByReference(Warrior& warrior) {
    Warrior* copy = &warrior;
    
    copy -> SetValue(20);
    copy -> PrintValue();
}

void PassByPointer(Warrior* warriorPointer) {
    Warrior* copy = warriorPointer;

    copy -> SetValue(30);
    copy -> PrintValue();
}


main() {

    std::cout << "Wrapper class : \n";
    Warrior warriorToBeWrapped (2);
    std::cout << &warriorToBeWrapped << "\n";
    warriorToBeWrapped.PrintValue();
    WarriorWrapper wrapper(warriorToBeWrapped);
    wrapper.Print();
    wrapper.SetValue(21);
    wrapper.Print();
    warriorToBeWrapped.PrintValue();

    std::cout << "By value : \n";
    Warrior warriorByValue (5);
    warriorByValue.PrintValue();

    PassByValue(warriorByValue);
    warriorByValue.PrintValue();

    std::cout << "By reference : \n";
    Warrior warriorByReference (7);
    warriorByReference.PrintValue();

    PassByReference(warriorByReference);
    warriorByReference.PrintValue();
    
    std::cout << "By pointer : \n";
    Warrior warriorByPointer (11);
    warriorByPointer.PrintValue();

    PassByPointer(&warriorByPointer);
    warriorByPointer.PrintValue();

    std::cout << "By value : \n";
    warriorByValue.PrintValue();
    std::cout << "By pointer : \n";
    warriorByReference.PrintValue();
    std::cout << "By reference : \n";
    warriorByPointer.PrintValue();
    

    return 0;
}