//
// Created by shani on 17/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_H
#define COWBOY_VS_NINJA_A_TEAM_H

#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <iostream>
using namespace std;

class Team{
public:
    Team(Character* chief) : _chief(chief){};
    ~Team();

    // add the fighter into the team
    void add(Character* fighter);

    // if this chief is not alive so peak another one which closets to the dead chief's location
    // the fighter that will be attacked by all this, is the one on the enemy team that stands closest to this chief.
    // if the victim is dead so a new victim will be chosen.
    void attack(Team* enemy);

    // number of fighters that still alive
    int stillAlive();

    // print the details on each member team
    string print();

    Character* getChief() { return this->_chief;}

private:
    const int _maxFighter = 10;
    std::vector<Character*> _fighters;
    Character* _chief;

};
#endif //COWBOY_VS_NINJA_A_TEAM_H
