#include <iostream>
#include <string>

class Warrior 
{
public:
    void attack() 
    {
        std::cout << "Warrior performs a basic attack!" << std::endl;
    }

    
    void attack(int damage) 
    {
        std::cout << "Warrior attacks and deals " << damage << " damage to the random rock!" << std::endl;
    }

    void attack(std::string spell, int damage) 
    {
        std::cout << "Warrior casts " << spell << " and deals " << damage << " magic damage to the random rock!" << std::endl;
    }
};

int main() 
{
    Warrior w;

    w.attack();                  // basic attack
    w.attack(50);                // attack with damage
    w.attack("Fireball", 100);   // spell attack

    return 0;
}