#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

class Warrior {
    private:
        std::string name;
        int health;
        int maxDamage;
        int maxBlock;

    public:
        Warrior() {};
        Warrior(std::string, int = 35, int = 15, int = 15);
        std::string GetName();
        int HealthLeft();
        int HitOther();
        int Block();
        void GetHitted(int);
        bool IsAlive();
};

Warrior::Warrior(std::string name, int health, int maxDamage, int maxBlock) {
    this->name = name;
    this->health = health;
    this->maxDamage = maxDamage;
    this->maxBlock = maxBlock;
}

std::string Warrior::GetName() {
    return name;
}

int Warrior::HealthLeft() {
    return health;
}

int Warrior::HitOther() {
    return rand() % (maxDamage + 1);
}

int Warrior::Block() {
    return rand() % (maxBlock + 1);
}

void Warrior::GetHitted(int hit) {
    health -= hit;
}

bool Warrior::IsAlive() {
    return health > 0;
}

class Battle {
    private:
        Warrior& attacker;
        Warrior& defender;
        void Swap();
    
    public:
        Battle(Warrior& first, Warrior& second);
        void StartFight();
};

Battle::Battle(Warrior& first, Warrior& second): attacker(first), defender(second) {
    std::cout << "First input memory : " << &first << "\n";
    std::cout << "First memory : " << &attacker << "\n";
    std::cout << "Second input memory : " << &second << "\n";
    std::cout << "Second memory : " << &defender << "\n";
}

void Battle::Swap() {
    Warrior temp = attacker;
    attacker = defender;
    defender = temp;
}

void Battle::StartFight() {
    srand(time(NULL));
    Swap();

    while (defender.IsAlive()) {
        Swap();

        int damage = attacker.HitOther() - defender.Block();
        if (damage < 0) damage = 0;
        defender.GetHitted(damage);

        std::cout << attacker.GetName() << " attacks " << defender.GetName() << " and does " << damage << " damage.\n";
        std::cout << defender.GetName() << " is down to " << defender.HealthLeft() << " health.\n";
    }

    std::cout << defender.GetName() << " has died and " << attacker.GetName() << " is victorious.\n";
    std::cout << "Game Over!\n";
}

int main() {

    Warrior hulk ("Hulk", 10, 15, 0);
    Warrior thor ("Thor", 10, 15, 0);

    std::cout << "hulk memory " << &hulk << std::endl; 
    std::cout << "thor memory " << &thor << std::endl; 

    Battle battle (hulk, thor);
    battle.StartFight();

    hulk.GetHitted(10);

    std::cout << hulk.HealthLeft() << "\n";
    std::cout << thor.HealthLeft() << "\n";

    return 0;
}