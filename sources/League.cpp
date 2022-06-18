#include "League.hpp"

namespace league
{
    League::League(std::vector<std::string> names, std::vector<double> talent)
    {
        this->names = names;
        this->teams = new std::vector<Team *>;
        for (size_t i = 0; i < names.size(); i++)
        {
            if (talent.size() == names.size())
            {
                Team *team = new Team(names.at(i), talent.at(i));
                this->teams->push_back(team);
            }
            else
            {
                Team *team = new Team(names.at(i));
                this->teams->push_back(team);
            }
        }
    }
    void League::buildSchedule()
    {
        Schedule *sc = new Schedule(*this, this->names);
        sc->playLeague();
        this->leas_points_against();
        this->leas_points_for();
        this->most_negative_points();
        this->most_positive_points();
        this->most_loss();
        this->most_wins();
    }
    void League::most_positive_points()
    {
        int max_points = this->teams->at(0)->points_for;
        size_t index = 0;
        for (size_t i = 0; i < 20; i++)
        {
            if (this->teams->at(i)->points_for > max_points)
            {
                index = i;
                max_points = this->teams->at(i)->points_for;
            }
        }
        std::cout << "The " << this->teams->at(index)->name << " scored most points with: " << this->teams->at(index)->points_for << " points\n";
    }
    void League::most_negative_points()
    {
        int max_points = this->teams->at(0)->points_against;
        size_t index = 0;
        for (size_t i = 0; i < 20; i++)
        {
            if (this->teams->at(i)->points_against > max_points)
            {
                index = i;
                max_points = this->teams->at(i)->points_against;
            }
        }
        std::cout << "The " << this->teams->at(index)->name << " got scored most points against with: " << this->teams->at(index)->points_against << " points\n";
    }
    void League::most_loss()
    {
        int max_points = this->teams->at(0)->loss;
        size_t index = 0;
        for (size_t i = 0; i < 20; i++)
        {
            if (this->teams->at(i)->loss > max_points)
            {
                index = i;
                max_points = this->teams->at(i)->loss;
            }
        }
        std::cout << "The " << this->teams->at(index)->name << " lost the most games with: " << this->teams->at(index)->loss << " games\n";
    }
    void League::most_wins(){
        int max_points = this->teams->at(0)->win;
        size_t index = 0;
        for (size_t i = 0; i < 20; i++)
        {
            if (this->teams->at(i)->win > max_points)
            {
                index = i;
                max_points = this->teams->at(i)->win;
            }
        }
        std::cout << "The " << this->teams->at(index)->name << " won the most games with: " << this->teams->at(index)->win << " games\n";
    }
    void League::leas_points_against()
    {
        int max_points = this->teams->at(0)->points_against;
        size_t index = 0;
        for (size_t i = 0; i < 20; i++)
        {
            if (this->teams->at(i)->points_against < max_points)
            {
                index = i;
                max_points = this->teams->at(i)->points_against;
            }
        }
        std::cout << "The " << this->teams->at(index)->name << " got scored the least points against with: " << this->teams->at(index)->points_against << " points\n";
    }
    void League::leas_points_for()
    {
        int max_points = this->teams->at(0)->points_for;
        size_t index = 0;
        for (size_t i = 0; i < 20; i++)
        {
            if (this->teams->at(i)->points_for < max_points)
            {
                index = i;
                max_points = this->teams->at(i)->points_for;
            }
        }
        std::cout << "The " << this->teams->at(index)->name << " scored the least points with: " << this->teams->at(index)->points_for << " points\n";
    }
}