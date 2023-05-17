//
// Created by shani on 17/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_NINJA_H
#define COWBOY_VS_NINJA_A_NINJA_H

#include "Character.hpp"

class Ninja : public Character{
public:
    Ninja(string name, Point location, int health, int speed) :
    Character(name, location, health), _speed(speed){};

    // The ninja get closer to the enemy accordingly to his speed
    void move(Character* enemy);

    // if the ninja is alive and the enemy is less than 1m' from him - so the ninja reduce 40 health from the enemy
    // otherwise - nothing will happen to the enemy
    void slash(Character* enemy);


protected:
    int _speed;

};

class YoungNinja : public Ninja{
public:
    YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {};
};

class TrainedNinja : public Ninja{
public:
    TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {};
};

class OldNinja : public Ninja{
public:
    OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {};
};

#endif //COWBOY_VS_NINJA_A_NINJA_H
