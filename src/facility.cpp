#include "../headers/facility.hpp"

bool Facility::addTeam(Team* team)
{
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (*teams[i] == *team)
        {
            return false;
        }
    }
    teams.push_back(team);
    return true;
}

bool Facility::removeTeam(Team team) //Tells whether the team is in the facility or not
{
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (*teams[i] == team)
        {
            delete teams[i];
            teams.erase(teams.begin() + i, teams.begin() + i + 1);
            return true;
        }
    }
    return false;
}

bool Facility::setCurrentTeam(const size_t& n)
{
    if (n > teams.size())
    {
        std::cout << "Select a valid team.";
        return false;
    }
    currentTeam = n;
    return true;
}

size_t Facility::getCurrentTeam() const
{
    return currentTeam;
}

size_t Facility::size() const
{
    return teams.size();
}

Team* Facility::operator[](size_t idx)
{
    return teams[idx];
}

std::ostream& Facility::listFootballTeams(std::ostream& os)
{
    size_t n = 1;
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (FootballTeam* ft = dynamic_cast<FootballTeam*>(teams[i])) //Checks whether the i. team is a Football Team or not
        {
            os << "\n" << n << ". Football team:" << "\n";
            teams[i]->print(os);
            n++;
        }
    }
    if (n == 1)
    {
        os << "This facility has no Football teams at the moment." << "\n";
    }
    return os;
}

std::ostream& Facility::listBasketballTeams(std::ostream& os)
{
    size_t n = 1;
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (BasketballTeam* bt = dynamic_cast<BasketballTeam*>(teams[i])) //Checks whether the i. team is a Football Team or not
        {
            os << "\n" << n << ". Basketball team:" << "\n";
            teams[i]->print(os);
            n++;
        }
    }
    if (n == 1)
    {
        os << "This facility has no Basketball teams at the moment." << "\n";
    }
    return os;
}

std::ostream& Facility::listHandballTeams(std::ostream& os)
{
    size_t n = 1;
    for (size_t i = 0; i < teams.size(); i++)
    {
        if (HandballTeam* ht = dynamic_cast<HandballTeam*>(teams[i])) //Checks whether the i. team is a Football Team or not
        {
            os << "\n" << n << ". Handball team:" << "\n";
            teams[i]->print(os);
            n++;
        }
    }
    if (n == 1)
    {
        os << "This facility has no Handball teams at the moment." << "\n";
    }
    return os;
}