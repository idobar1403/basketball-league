#include "Team.hpp"


namespace league
{
    Team::Team(const std::string name)
    {
        this->name = name;
        this->loss = 0;
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> random_talent(0, 1.0);
        this->talent = random_talent(gen);
        this->win = 0;
        this->win_loss_ratio = 0;
        this->best_win_streak = 0;
        this->curr_loss_streak = 0;
        this->curr_win_streak = 0;
        this->points_against = 0;
        this->points_for = 0;
        this->worst_loss_streak = 0;
    }
    Team::Team(std::string name, double talent)
    {
        this->name = name;
        this->talent = talent;
        this->loss = 0;
        this->win = 0;
        this->win_loss_ratio = 0;
        this->best_win_streak = 0;
        this->curr_loss_streak = 0;
        this->curr_win_streak = 0;
        this->worst_loss_streak = 0;
        this->points_against = 0;
        this->points_for = 0;
    }
    void Team::lost()
    {
        this->loss++;
        this->curr_loss_streak++;
        if (this->curr_win_streak > this->best_win_streak)
        {
            this->best_win_streak = this->curr_win_streak;
        }
        this->curr_win_streak = 0;
    }
    void Team::won()
    {
        this->win++;
        this->curr_win_streak++;
        if (this->curr_loss_streak > this->worst_loss_streak)
        {
            this->worst_loss_streak = this->curr_loss_streak;
        }
        this->curr_loss_streak = 0;
    }

    void Team::update_points(int p_for, int p_against)
    {
        if(p_for>p_against){
            won();
        }
        else{
            lost();
        }
        this->points_for += p_for;
        this->points_against += p_against;
    }

}