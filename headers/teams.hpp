#ifndef TEAMS_HPP
#define TEAMS_HPP

#include "person.hpp"

class Team
{
private:
    std::string name;
    std::vector<Person> players;
public:
    Team(std::string name): name(name) {}

    bool addPlayer(const Person& player);
    bool removePlayer(const Person& player);
    bool operator==(const Team& team);
    Person& getPlayer(size_t idx);
    std::string getName() const;
    size_t size() const;

    virtual std::ostream& print(std::ostream& os);

    virtual ~Team() {}
};

class FootballTeam : public Team
{
private:
    std::vector<Person> coaches;
public:
    FootballTeam(std::string name): Team(name) {}

    bool addCoach(const Person& coach);
    bool removeCoach(const Person& coach);
    Person& getCoach(size_t idx);
    size_t numberOfCoaches() const;

    std::ostream& print(std::ostream& os);

    ~FootballTeam() {}
};

class BasketballTeam : public Team
{
private:
    std::vector<Person> cheerleaders;
public:
    BasketballTeam(std::string name): Team(name) {}

    bool addCheerleader(const Person& cheerleader);
    bool removeCheerleader(const Person& cheerleader);
    Person& getCheerleader(size_t idx);
    size_t numberOfCheerleaders();

    std::ostream& print(std::ostream& os);

    ~BasketballTeam() {}
};

class HandballTeam : public Team
{
private:
    size_t supportMoney;
public:
    HandballTeam(std::string name, size_t value = 0): Team(name), supportMoney(value) {}

    void changeSupportMoney(size_t newValue);
    size_t getValue() const;

    std::ostream& print(std::ostream& os);

    ~HandballTeam() {}
};

#endif