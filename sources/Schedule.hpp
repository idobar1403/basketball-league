#ifndef SCHEDULE_CPP
#define SCHEDULE_CPP
#include "League.hpp"
#include <iostream>
#include "Game.hpp"
#include <vector>
#include <map>
#include <string>
namespace league
{
    class League;
    class Schedule
    {
    public:
        std::vector<std::string> teams_names;
        std::vector<std::vector<Game*>>games;
        Schedule(League &leag, std::vector<std::string>);
        void buildGames(League *leag);
        void playLeague();

    };
}
#endif