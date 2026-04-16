#include <iostream>
#include <string>
using namespace std;

//Base Class 
class Pokemon {
protected:
    int level;
    string name;

public:
    Pokemon(int lvl, string n) : level(lvl), name(n) {}
    virtual ~Pokemon() {}

    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;

    virtual void display() const 
    {
        cout << "Name: " << name << " | Level: " << level << endl;
    }
};

// Type Classes 
class ElectricPokemon : public Pokemon {
public:
    ElectricPokemon(int lvl, string n) : Pokemon(lvl, n) {}

    void attack() const override {
        cout << name << " uses Thunderbolt! " << endl;
    }

    void defend() const override {
        cout << name << " uses Static Shield! " << endl;
    }

    void evolve() override {
        level++;
        cout << name << " (Electric type) evolved! Now level " << level << endl;
    }
};

class FirePokemon : public Pokemon {
public:
    FirePokemon(int lvl, string n) : Pokemon(lvl, n) {}

    void attack() const override {
        cout << name << " uses Flamethrower! " << endl;
    }

    void defend() const override {
        cout << name << " uses Fire Shield! " << endl;
    }

    void evolve() override {
        level++;
        cout << name << " (Fire type) evolved! Now level " << level << endl;
    }
};

class WaterPokemon : public Pokemon {
public:
    WaterPokemon(int lvl, string n) : Pokemon(lvl, n) {}

    void attack() const override {
        cout << name << " uses Hydro Pump! " << endl;
    }

    void defend() const override {
        cout << name << " uses Aqua Guard! " << endl;
    }

    void evolve() override {
        level++;
        cout << name << " (Water type) evolved! Now level " << level << endl;
    }
};

// Specific Pokemon Classes
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int lvl) : ElectricPokemon(lvl, "Pikachu") {
        cout << "Pikachu created at level " << lvl <<  endl;
    }

    void evolve() override {
        name = "Raichu";
        level += 5;
        cout << "Pikachu evolved into Raichu! Now level " << level << endl;
    }
};

class Charmander : public FirePokemon {
public:
    Charmander(int lvl) : FirePokemon(lvl, "Charmander") {
        cout << "Charmander created at level " << lvl << "! " << endl;
    }

    void evolve() override {
        name = "Charmeleon";
        level += 5;
        cout << "Charmander evolved into Charmeleon! Now level " << level  << endl;
    }
};

class Squirtle : public WaterPokemon {
public:
    Squirtle(int lvl) : WaterPokemon(lvl, "Squirtle") {
        cout << "Squirtle created at level " << lvl << "! " << endl;
    }

    void evolve() override {
        name = "Wartortle";
        level += 5;
        cout << "Squirtle evolved into Wartortle! Now level " << level << endl;
    }
};


int main() {
    // Part 1: Inheritance hierarchy
    Pikachu pikachu(10);
    Charmander charmander(5);
    Squirtle squirtle(5);

    cout << "\n--- Display ---" << endl;
    pikachu.display();
    charmander.display();
    squirtle.display();

    // Part 2: Polymorphism via base class pointer
    cout << "\n--- Polymorphic Attack ---" << endl;
    Pokemon* team[] = { &pikachu, &charmander, &squirtle };
    for (Pokemon* p : team) {
        p->attack();
        p->defend();
    }

    cout << "\n--- Evolving ---" << endl;
    for (Pokemon* p : team) {
        p->evolve();
    }

    return 0;
}