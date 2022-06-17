#ifndef TEAM_CPP
#define TEAM_CPP
#pragma once
#include <iostream>
#include "Game.hpp"
#include <string>
#include <vector>
#include <random>

namespace league
{
    class Team
    {
    public:
        explicit Team(std::string name);
        Team(std::string name, double talent);
        double talent;
        std::string name;
        int win;
        int loss;
        double win_loss_ratio;
        int points_for;
        int points_against;
        int curr_win_streak;
        int curr_loss_streak;
        int best_win_streak;
        int worst_loss_streak;
        void won();
        void lost();
        void update_points(int p_for, int p_against);
    };
}
#endif