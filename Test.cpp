//
// Created by shani on 17/05/2023.
//

#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Team.hpp"
#include "doctest.h"
#include <stdexcept>
#include <sstream>
#include <random>
using namespace std;

TEST_CASE("Creation") {

    /// create tom_team
    TrainedNinja* tom_n_chief = new TrainedNinja("Tom", Point(0, 0));
    Team* tom_team = new Team(tom_n_chief);

    Ninja* tom_n = new Ninja("tom_n", Point(1, 1), 100, 10);
    TrainedNinja* tom_t_n = new TrainedNinja("tom_t_n", Point(5, 10));
    YoungNinja* tom_y_n = new YoungNinja("tom_y_n", Point(3, 2));
    Cowboy* tom_c = new Cowboy("tom_c", Point(4, 8));

    /// add fighters for tom_team
    CHECK_NOTHROW(
        tom_team->add(tom_n);
        tom_team->add(tom_t_n);
        tom_team->add(tom_y_n);
        tom_team->add(tom_c);
    );

    CHECK(tom_team->stillAlive() == 5);

    /// create shon_team
    Cowboy* shon_c_chief = new Cowboy("Shon", Point(0, 0));
    Team* shon_team = new Team(shon_c_chief);

    Ninja* shon_n = new Ninja("shon_n", Point(7, 7), 100, 7);
    TrainedNinja* shon_t_n = new TrainedNinja("shon_t_n", Point(13, 2));
    YoungNinja* shon_y_n = new YoungNinja("shon_y_n", Point(1, 1));
    Cowboy* shon_c = new Cowboy("shon_c", Point(6, 3));

    /// add fighters for shon_team
    CHECK_NOTHROW(
        shon_team->add(shon_n);
        shon_team->add(shon_t_n);
        shon_team->add(shon_y_n);
        shon_team->add(shon_c);
    );


    CHECK(shon_team->stillAlive() == 5);

    SUBCASE("attack"){
        /// Cowboy attack the CHIEF ninja until is dead
        /// Check the bullets in cowboy gun (initialize, over, reload)

        // number of bullets before shooting
        CHECK(shon_c->getNumOfBullets() == 6);

        // for TrainedNinja has 120 health, each shooting reduce 10
        for (int i = 0; i < 6; ++i) {
            CHECK(tom_n_chief->isAlive() == true);
            shon_c->shoot(tom_n_chief);
            CHECK(shon_c->hasboolets() == true);
        }
        CHECK(tom_n_chief->getHealth() == 60);
        // each cowboy has at most 6 bullets
        CHECK(shon_c->hasboolets() == false);
        CHECK(shon_c_chief->getNumOfBullets() == 0);

        //reload bullets
        shon_c->reload();
        CHECK(shon_c->getNumOfBullets() == 6);

        for (int i = 0; i < 6; ++i) {
            CHECK(tom_n_chief->isAlive() == true);
            shon_c->shoot(tom_n_chief);
            CHECK(shon_c->hasboolets() == true);
        }
        // the chief need to be dead
        CHECK(tom_n_chief->isAlive() == false);
        CHECK(tom_n_chief->getHealth() == 0);

        /// Check while tom_team attack so the chief is replaced
        CHECK(tom_team->getChief() == tom_n_chief);
        tom_team->attack(shon_team);
        // the chief of tom_team need to be replaced to the closet team member
        CHECK(tom_team->getChief() == tom_n);
    }

    SUBCASE("print"){
        // print of a character
        CHECK_NOTHROW(shon_c_chief->print());
        CHECK_NOTHROW(tom_n_chief->print());

        // print of a team
        CHECK_NOTHROW(tom_team->print());
        CHECK_NOTHROW(shon_team->print());
    }


    SUBCASE("overload"){
        /// check that a team cant be with more 10 fighters
        for (int i = 0; i < 5; ++i) {
            YoungNinja* ninja = new YoungNinja("a", Point(0,0));
            CHECK_NOTHROW(shon_team->add(ninja));
        }
        // now shon_team has 10 fighters exactly
        YoungNinja* extraNinja = new YoungNinja("a", Point(0,0));
        CHECK_THROWS(shon_team->add(extraNinja));
    }
};
