#ifndef LEAGUE_CPP
#define LEAGUE_CPP
#include "Schedule.hpp"
#include "Team.hpp"

namespace league
{
    class Team;
    class League
    {
    public:
        League(std::vector<std::string> names, std::vector<double> talent);
        std::vector<Team *>*teams;
        std::vector<std::string> names;
        void buildSchedule();
        League()
        {
            this->teams = new std::vector<Team*>[20];
            for (size_t i = 0; i < this->teamsNames.size(); i++)
            {
                // Team *curr = new Team(this->teamsNames.at(i));
                Team curr{this->teamsNames.at(i)};
                this->teams->push_back(&curr);
                std::cout << "here";
            }
        }
        std::vector<std::string> teamsNames = {
            "Lakers",
            "Cavaliers",
            "Nicks",
            "Celtics",
            "Clippers",
            "Raptors",
            "Bulls",
            "Bucks",
            "Wizards",
            "Heat",
            "Rockets",
            "Spurs",
            "Suns",
            "Grizzlies",
            "Nuggets",
            "Jazz",
            "Pistons",
            "Magic",
            "Pelicans",
            "Warriors",
        };
        std::vector<double> talent = {0, 0.5, 0.2, 0.1, 0.2, 0.4, 1, 0.4, 0.7, 0.6, 0.5, 0.3, 0.9, 0.8, 0.6, 0.5, 0, 0.4, 0.2, 1};
    };
}
#endif