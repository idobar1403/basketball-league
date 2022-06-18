#include "Game.hpp"

namespace league
{
    Game::Game(Team &home, Team &away)
    {
        this->home = &home;
        this->away = &away;
    }
    void Game::play_game()
    {
        int home_points = this->generate_points_home();
        int away_points = this->generate_points_away();
        home_points += (int)round(this->home->talent * (double)talent_points);
        away_points += (int)round(this->away->talent * (double)talent_points);
        this->home->update_points(home_points, away_points);
        this->away->update_points(away_points, home_points);
    }
    void Game::update_teams(Team &win, Team &loss)
    {
        win.won();
        loss.lost();
    }
    int Game::generate_points_home()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> random_points(min_home, max_points);
        return random_points(gen);
    }

    int Game::generate_points_away()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> random_points(min_away, max_points);
        return random_points(gen);
    }
}