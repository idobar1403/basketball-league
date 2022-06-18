#include "doctest.h"
#include"sources/League.hpp"
#include"sources/Team.hpp"
#include"sources/Game.hpp"
#include"sources/Schedule.hpp"
TEST_CASE("make league")
{
    std::vector<std::string> teamsNames = {
        "Lakers","Cavaliers",
        "Nicks","Celtics",
        "Clippers","Raptors",
        "Bulls","Bucks",
        "Wizards","Heat",
        "Rockets","Spurs",
        "Suns","Grizzlies",
        "Nuggets","Jazz",
        "Pistons","Magic",
        "Pelicans","Warriors",
    };
    std::vector<double> talent ={0,0.5,0.2,0.1,0.2,0.4,1,0.4,0.7,0.6,0.5,0.3,0.9,0.8,0.6,0.5,0,0.4,0.2,1};
    // CHECK_NOTHROW(League leag(teamsNames,talent););
    league::League leag(teamsNames,talent);
    // CHECK_NOTHROW(leag.buildSchedule(););
    leag.buildSchedule();
}