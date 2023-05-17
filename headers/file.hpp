#ifndef FILE_HPP
#define FILE_HPP

#include "facility.hpp"
#include "json.hpp"

class FileHandler
{
private:
    std::string fPath;
    std::string bPath;
    std::string hPath;

public:
    FileHandler(std::string fileF, std::string fileB, std::string fileH): fPath(fileF), bPath(fileB) , hPath(fileH) {}

    std::vector<FootballTeam*> readFootballTeams();
    std::vector<BasketballTeam*> readBasketballTeams();
    std::vector<HandballTeam*> readHandballTeams();

    void writeFootballTeam(std::vector<FootballTeam*> ft);
    void writeBasketballTeam(std::vector<BasketballTeam*> ft);
    void writeHandballTeam(std::vector<HandballTeam*> ft);

    Facility readFacility();
    void writeFacility(Facility changedFacility);
};


#endif