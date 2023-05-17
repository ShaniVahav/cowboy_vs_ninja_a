//
// Created by shani on 16/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_CHARACTER_H
#define COWBOY_VS_NINJA_A_CHARACTER_H

#include "Point.hpp"
#include <iostream>
using namespace std;
namespace ariel{}


/// The class represents an character in the game

class Character {
public:
    Character(string name, Point location, int health) : _name(name), _location(location), _health(health){}

    // if character 'hits_left' > 0 so he is alive
    bool isAlive();

    // get pointer to another character and return the distance from this character
    double distance(Character* other);

    // get the number of hit in this character
    // reduce the num of hits from 'health' attribute
    void hit (int num);

    // print the: N - for ninja, C - cowboy, {name, number of hits, location} of the character
    // if the character is not alive - number of hits will not be printed and the name will be in parentheses
    string print();

    string getName() { return this->_name; }

    Point getLocation() {return this->_location; }

    int getHealth(){return this->_health;}

protected:
    string _name;
    Point _location;
    int _health;  // number of hits that the character can get and stay alive
};


#endif //COWBOY_VS_NINJA_A_CHARACTER_H
