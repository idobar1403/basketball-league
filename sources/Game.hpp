#ifndef GAME_CPP
#define GAME_CPP
#pragma once
#include <iostream>
#include "Team.hpp"

namespace league{
    constexpr int max_points = 100;
    constexpr int min_away = 50;
    constexpr int min_home = 55;
    constexpr double talent_points = 10;
    class Team;
    class Game{
        Team *home;
        Team *away;
        public:
            Game(Team &home, Team &away);
            void play_game();
            void update_teams(Team &win, Team &loss);
            int generate_points_home();
            int generate_points_away();
    };
}
#endif