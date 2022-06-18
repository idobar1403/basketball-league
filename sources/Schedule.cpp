#include "Schedule.hpp"

namespace league
{
    Schedule::Schedule(League &leag, std::vector<std::string> names)
    {
        this->teams_names = names;
        this->buildGames(&leag);
    }
    void Schedule::buildGames(League *leag)
    {
        std::map<std::string, int> currGame;
        std::map<std::string, int> played;
        for (int i = 0; i < 38; i++)
        {
            auto vec = new std::vector<Game *>();
            this->games.push_back(*vec);
            for (size_t j = 0; j < 20; j++)
            {
                std::string str = std::to_string(i);
                played.insert({this->teams_names.at(j) + "," + str, 1});
            }
        }
        for (size_t i = 0; i < 20; i++)
        {
            for (size_t j = 0; j < 20; j++)
            {
                if (i == j)
                {
                    continue;
                }
                currGame.insert({this->teams_names.at(i) + "," + this->teams_names.at(j), 1});
            }
        }
        for (size_t i = 0; i < 20; i++)
        {
            for (size_t j = 0; j < 20; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (currGame.at(this->teams_names.at(i) + "," + this->teams_names.at(j)) == 1)
                {
                    for (size_t h = 0; h < 38; h++)
                    {
                        std::string round = std::to_string((h));
                        if (played.at(this->teams_names.at(i) + "," + round) == 1)
                        {
                            if (played.at(this->teams_names.at(j) + "," + round) == 1)
                            {
                                Game *game = new Game(*(leag->teams->at(i)), *(leag->teams->at(j)));
                                this->games.at((h)).push_back(game);
                                currGame[this->teams_names.at(i) + "," + this->teams_names.at(j)] = 0;
                                played[(this->teams_names.at(j) + "," + round)] = 0;
                                played[(this->teams_names.at(i) + "," + round)]= 0;
                            }
                        }
                    }
                }
                else if (currGame.at(this->teams_names.at(j) + "," + this->teams_names.at(i)) == 1)
                {
                    for (size_t h = 0; h < 38; h++)
                    {
                        std::string round = std::to_string((h));
                        if (played.at(this->teams_names.at(i) + "," + round) == 1)
                        {
                            if (played.at(this->teams_names.at(j) + "," + round) == 1)
                            {
                                Game *game = new Game(*(leag->teams->at(j)), *(leag->teams->at(i)));
                                this->games.at((h)).push_back(game);
                                currGame[(this->teams_names.at(j) + "," + this->teams_names.at(i))] = 0;
                                played[(this->teams_names.at(j) + "," + round)] = 0;
                                played[(this->teams_names.at(i) + "," + round)] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    void Schedule::playLeague()
    {
        int rounds = 38;
        int matches = 10;
        for (size_t i = 1; i < rounds; i++)
        {
            for (size_t j = 0; j < matches; j++)
            {
                this->games[i][j]->play_game();
            }
        }
    }
}