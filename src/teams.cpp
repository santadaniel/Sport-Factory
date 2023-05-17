#include "../headers/teams.hpp"

//Team member functions
bool Team::addPlayer(const Person& player)
{
    for (size_t i = 0; i < players.size(); i++)
    {
        if (players[i] == player)
        {
            return false;
        }
    }
    players.push_back(player);
    return true;
}

bool Team::removePlayer(const Person& player) //Tells whether the player is in the team or not
{
    for (size_t i = 0; i < players.size(); i++)
    {
        if (players[i] == player)
        {
            players.erase(players.begin() + i, players.begin() + i + 1);  
            return true;       
        }
    }
    return false;
}

bool Team::operator==(const Team& team)
{
    return (name == team.name);
}

std::string Team::getName() const
{
    return name;
}

size_t Team::size() const
{
    return players.size();
}

Person& Team::getPlayer(size_t idx)
{
    return players[idx];
}

std::ostream& Team::print(std::ostream& os)
{
    os << "Team name: " << name << "\n";
    os << "Players: " << "\n";
    for (size_t i = 0; i < players.size(); i++)
    {
        os << "\t" << players[i].getName() << ", Age: " << players[i].getAge();
        os << "\n";
    }
    return os;
}

//FootballTeam member functions
bool FootballTeam::addCoach(const Person& coach)
{
    for (size_t i = 0; i < coaches.size(); i++)
    {
        if (coaches.size() == 2 || coaches[i] == coach) //maximum number of coaches is 2
        {
            return false;
        }
    }
    coaches.push_back(coach);
    return true;
}

bool FootballTeam::removeCoach(const Person& coach) //Tells whether the coach is in the team or not
{
    for (size_t i = 0; i < coaches.size(); i++)
    {
        if (coaches[i] == coach)
        {
            coaches.erase(coaches.begin() + i, coaches.begin() + i + 1);
            return true;         
        }
    }
    return false;
}

Person& FootballTeam::getCoach(size_t idx)
{
    return coaches[idx];
}

size_t FootballTeam::numberOfCoaches() const
{
    return coaches.size();
}

std::ostream& FootballTeam::print(std::ostream& os)
{
    Team::print(os);
    switch (coaches.size())
    {
        case 1:
            os << "Coach: " << "\n";
            os << "\t" << coaches[0].getName() << ", Age: " << coaches[0].getAge() << "\n";
        break;
        case 2:
            os << "Coaches: " << "\n";
            os << "\t" << coaches[0].getName() << ", Age: " << coaches[0].getAge() << "\n";
            os << "\t" << coaches[1].getName() << ", Age: " << coaches[1].getAge() << "\n";
        break;
        default:
            os << "This Football Team has no coaches at the moment." << "\n";
        break;
    }
    return os;    
}

//BasketballTeam member functions
bool BasketballTeam::addCheerleader(const Person& cheerleader)
{
    for (size_t i = 0; i < cheerleaders.size(); i++)
    {
        if (cheerleaders[i] == cheerleader)
        {
            return false;
        }
    }
    cheerleaders.push_back(cheerleader);
    return true;
}

bool BasketballTeam::removeCheerleader(const Person& cheerleader) //Tells whether the cheerleader is in the team or not
{
    for (size_t i = 0; i < cheerleaders.size(); i++)
    {
        if (cheerleaders[i] == cheerleader)
        {
            cheerleaders.erase(cheerleaders.begin() + i, cheerleaders.begin() + i + 1);
            return true;
        }
    }
    return false;
}

Person& BasketballTeam::getCheerleader(size_t idx)
{
    return cheerleaders[idx];
}

size_t BasketballTeam::numberOfCheerleaders()
{
    return cheerleaders.size();
}

std::ostream& BasketballTeam::print(std::ostream& os)
{
    Team::print(os);
    switch (cheerleaders.size())
    {
        case 0:
            os << "This Basketball Team has no cheerleaders at the moment." << "\n";
        break;
        case 1:
            os << "Cheerleader: " << "\n";
            os << "\t" << cheerleaders[0].getName() << ", Age: " << cheerleaders[0].getAge() << "\n";
        break;
        default:
            os << "Cheerleaders: " << "\n";
            for (size_t i = 0; i < cheerleaders.size(); i++)
            {
                os << "\t" << cheerleaders[i].getName() << ", Age: " << cheerleaders[i].getAge() << "\n";
            }
        break;
    }
    return os;
}

//HandballTeam member functions
void HandballTeam::changeSupportMoney(size_t newValue)
{
    supportMoney = newValue;
}

size_t HandballTeam::getValue() const
{
    return supportMoney;
}

std::ostream& HandballTeam::print(std::ostream& os)
{
    Team::print(os);
    os << "Value of the yearly support money: $" << supportMoney << "\n";
    return os;
}