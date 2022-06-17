#include<iostream>
#include"sources/League.hpp"
#include"sources/Team.hpp"
#include"sources/Game.hpp"
#include"sources/Schedule.hpp"
#include<vector>
#include<string>
using namespace league;
int main(){
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
    Team t(teamsNames.at(0),0.0);
    std::cout<<t.name;
}