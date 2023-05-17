#ifndef FACILITY_HPP
#define FACILITY_HPP

#include <fstream>
#include "teams.hpp"
#include "json.hpp"

class Facility
{
private:
    std::vector<Team*> teams;
    size_t currentTeam;
public:
    bool addTeam(Team* team);
    bool removeTeam(Team team);
    bool setCurrentTeam(const size_t& n);
    size_t getCurrentTeam() const;
    size_t size() const;
    Team* operator[](size_t idx);

    template<typename C>
    C* getTeam(size_t idx)
    {
        size_t n = 0;
        for (size_t i = 0; i < teams.size(); i++)
        {
            C* t;
            if ((t = dynamic_cast<C*>(teams[i])))
            {
                n++;
            }
            if (idx == n)
            {
                return t;
            }
        }
        return nullptr;
    }   

    std::ostream& listFootballTeams(std::ostream& os);
    std::ostream& listBasketballTeams(std::ostream& os);
    std::ostream& listHandballTeams(std::ostream& os);

    ~Facility() 
    {
        for (size_t i = 0; i < teams.size(); i++)
        {
            delete teams[i];
        }
    }
};

#endif