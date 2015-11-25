/****************************************************************
 * Simple program where a human hero battles various monsters.
 * The monster will be allocated randomly inside a factory method
 * and returned to the game engine.
 *
 * In this version the human battles the spawn at the same time
 * instead of one at a time in sequence. Therefore the battle
 * method need to hold an array of Character pointers.
 * The inheritance hierarchy should not need to be changed.
 * You should just need to work on three functions: spawn, battle,
 * and main. Replace the raw pointers with unique_ptrs including
 * the raw pointer to the array of Character pointers.
 ****************************************************************/

#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;

class Character
{
public:
    Character() { ++Character::count;  }
    Character(std::string name, int health) : m_name(name), m_health(health) { ++Character::count;  }
    int health() { return m_health; }
    std::string name() { return m_name; }
    virtual void strike(Character& other) {
        //standard hit takes one health point
        other.takeHit(1);
    }
    void takeHit(int hit) {
        m_health-=hit; if (m_health < 0) m_health = 0;
    }
    void displayHealth() {
        cout << m_name
             << " takes a hit. Down to " << m_health
             << " hit points." << endl;
        if (m_health == 0) { cout << m_name << " is dead." << endl;}
    }
    virtual ~Character() { --Character::count; }
 
    static size_t live() {
        return Character::count;
    }
 
private:
    static size_t count;
    std::string m_name;
    int m_health;
};

size_t Character::count = 0;
 
 
struct Monster : Character
{
    Monster(std::string name, int health) : Character(name, health) {}
};
 
struct Human : Character
{
    Human(std::string name, int health) : Character(name, health) {}
};
 
struct Zombie : public Monster
{
    Zombie(std::string name, int health) : Monster(name, health) {}
};
 
struct Creeper : Monster
{
    Creeper(std::string name, int health) : Monster(name, health) {}
    virtual void strike(Character& other) {
        // Creepers are unusually strong their hit takes two health points
        other.takeHit(2);
    }
};
  
Character* spawn()
{
    if (rand() % 2 == 0)
        return new Zombie("Zombie", rand() % 15 + 2);
    else
        return new Creeper("Creeper", rand() % 10 + 2);
}
  
bool battle(Character* hero, int numSpawn)
{
    //battle numSpawn spawn at the same time
    Character** foes = new Character*[numSpawn];
  
    for (int i = 0; i < numSpawn; ++i)
    {
        foes[i] = spawn();
    }
    int liveFoes = numSpawn;
  
    do
    {
        
        //pick a random foe to fight
        Character*& foe = foes[rand() % numSpawn];

        if (!foe) {
            continue;
        }
  
  
        if (rand() % 2 == 0) {
            hero->strike(*foe);
            foe->displayHealth();
        }
        else {
            foe->strike(*hero);
            hero->displayHealth();
        }
  
        if (foe->health() == 0) {
            delete foe;
            foe = nullptr;
            --liveFoes;
        }
  
        if (hero->health() == 0) {
            for (int i = 0; i < numSpawn; ++i) {
                delete foes[i];
            }
            delete [] foes;
            delete hero;
            return false;
        }
    } while (hero->health() != 0 && liveFoes > 0);
    
    delete [] foes;
    delete hero;
    return true;
}
  
int main()
{
    srand(time(0));
    if (battle(new Human("Bradley", 120), 10)) {
        cout << "Bradley has defeted the spawn!" << endl;
    }
     
    cout << "Number of Character instances still in memory: "
         << Character::live() << endl;
}
