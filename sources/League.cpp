#include "League.hpp"

namespace league{
    League::League(std::vector<std::string> names, std::vector<double> talent){
        this->names = names;
        this->teams = new std::vector<Team*>(20);
        
        for(size_t i = 0;i<names.size();i++){
            if(talent.size()==names.size()){
            Team *team = new Team(names.at(i), talent.at(i));
            this->teams->push_back(team);
            }
            else{
                Team *team = new Team(names.at(i));
                this->teams->push_back(team);
            }
        }
    }
    void League::buildSchedule(){
        Schedule *sc =new Schedule(*this,this->names);
        sc->playLeague();
    }
}