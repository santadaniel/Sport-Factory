#include "../headers/file.hpp"

using json = nlohmann::json;

std::vector<FootballTeam*> FileHandler::readFootballTeams()
{
    std::vector<FootballTeam*> ret;
    std::ifstream ifs(fPath);
    json football = json::parse(ifs);
    ifs.close();
    auto teams = football["teams"];
    for (size_t i = 0; i < teams.size(); i++)
    {
        auto team = teams[i];
        FootballTeam* newTeam = new FootballTeam(team["name"]);
        for (size_t j = 0; j < team["players"].size(); j++)
        {
            std::string name = team["players"][j]["name"];
            size_t age = team["players"][j]["age"];
            newTeam->addPlayer(Person(name, age));
        }
        for (size_t j = 0; j < team["coaches"].size(); j++)
        {
            std::string name = team["coaches"][j]["name"];
            size_t age = team["coaches"][j]["age"];
            newTeam->addCoach(Person(name, age));
        }
        ret.push_back(newTeam);
    }
    return ret;
}

std::vector<BasketballTeam*> FileHandler::readBasketballTeams()
{
    std::vector<BasketballTeam*> ret;
    std::ifstream ifs(bPath);
    json basketball = json::parse(ifs);
    ifs.close();
    auto teams = basketball["teams"];
    for (size_t i = 0; i < teams.size(); i++)
    {
        auto team = teams[i];
        BasketballTeam* newTeam = new BasketballTeam(team["name"]);
        for (size_t j = 0; j < team["players"].size(); j++)
        {
            std::string name = team["players"][j]["name"];
            size_t age = team["players"][j]["age"];
            newTeam->addPlayer(Person(name, age));
        }
        for (size_t j = 0; j < team["cheerleaders"].size(); j++)
        {
            std::string name = team["cheerleaders"][j]["name"];
            size_t age = team["cheerleaders"][j]["age"];
            newTeam->addCheerleader(Person(name, age));
        }
        ret.push_back(newTeam);
    }
    return ret;
}
std::vector<HandballTeam*> FileHandler::readHandballTeams()
{
    std::vector<HandballTeam*> ret;
    std::ifstream ifs(hPath);
    json handball = json::parse(ifs);
    ifs.close();
    auto teams = handball["teams"];
    for (size_t i = 0; i < teams.size(); i++)
    {
        auto team = teams[i];
        HandballTeam* newTeam = new HandballTeam(team["name"], team["supportMoney"]);
        for (size_t j = 0; j < team["players"].size(); j++)
        {
            std::string name = team["players"][j]["name"];
            size_t age = team["players"][j]["age"];
            newTeam->addPlayer(Person(name, age));
        }   
        ret.push_back(newTeam);
    }
    return ret;
}

Facility FileHandler::readFacility()
{
    Facility ret;

    std::vector<FootballTeam*> fT = FileHandler::readFootballTeams();
    std::vector<BasketballTeam*> fB = FileHandler::readBasketballTeams();
    std::vector<HandballTeam*> fH = FileHandler::readHandballTeams();

    for (size_t i = 0; i < fT.size(); i++)
    {
        ret.addTeam(fT[i]);
    }
    for (size_t i = 0; i < fB.size(); i++)
    {
        ret.addTeam(fB[i]);
    }
    for (size_t i = 0; i < fH.size(); i++)
    {
        ret.addTeam(fH[i]);
    }
    return ret;
}

void FileHandler::writeFootballTeam(std::vector<FootballTeam*> ft)
{
    std::vector<json> teams;
    for (size_t i = 0; i < ft.size(); i++)
    {   
        FootballTeam* currentTeam = ft[i];

        json team;
        team["name"] = currentTeam->getName();

        std::vector<json> players;
        for (size_t j = 0; j < currentTeam->size(); j++)
        {
            Person currentPlayer = currentTeam->getPlayer(j);
            json player;
            player["name"] = currentPlayer.getName();
            player["age"] = currentPlayer.getAge();
            players.push_back(player);
        }
        team["players"] = players;

        std::vector<json> coaches;
        for (size_t j = 0; j < currentTeam->numberOfCoaches(); j++)
        {
            Person currentCoach = currentTeam->getCoach(j);
            json coach;
            coach["name"] = currentCoach.getName();
            coach["age"] = currentCoach.getAge();
            coaches.push_back(coach);
        }
        team["coaches"] = coaches;

        teams.push_back(team);
    }

    json football;
    football["teams"] = teams;
    std::ofstream of(fPath);
    of << football.dump();
    of.close(); 
}

void FileHandler::writeBasketballTeam(std::vector<BasketballTeam*> bt)
{
    std::vector<json> teams;
    for (size_t i = 0; i < bt.size(); i++)
    {   
        BasketballTeam* currentTeam = bt[i];

        json team;
        team["name"] = currentTeam->getName();

        std::vector<json> players;
        for (size_t j = 0; j < currentTeam->size(); j++)
        {
            Person currentPlayer = currentTeam->getPlayer(j);
            json player;
            player["name"] = currentPlayer.getName();
            player["age"] = currentPlayer.getAge();
            players.push_back(player);
        }
        team["players"] = players;

        std::vector<json> cheerleaders;
        for (size_t j = 0; j < currentTeam->numberOfCheerleaders(); j++)
        {
            Person currentCheerleader = currentTeam->getCheerleader(j);
            json cheerleader;
            cheerleader["name"] = currentCheerleader.getName();
            cheerleader["age"] = currentCheerleader.getAge();
            cheerleaders.push_back(cheerleader);
        }
        team["cheerleaders"] = cheerleaders;

        teams.push_back(team);
    }

    json basketball;
    basketball["teams"] = teams;
    std::ofstream of(bPath);
    of << basketball.dump();
    of.close(); 
}

void FileHandler::writeHandballTeam(std::vector<HandballTeam*> ht)
{
    std::vector<json> teams;
    for (size_t i = 0; i < ht.size(); i++)
    {   
        HandballTeam* currentTeam = ht[i];

        json team;
        team["name"] = currentTeam->getName();

        std::vector<json> players;
        for (size_t j = 0; j < currentTeam->size(); j++)
        {
            Person currentPlayer = currentTeam->getPlayer(j);
            json player;
            player["name"] = currentPlayer.getName();
            player["age"] = currentPlayer.getAge();
            players.push_back(player);
        }
        team["players"] = players;

        team["supportMoney"] = currentTeam->getValue();

        teams.push_back(team);
    }

    json handball;
    handball["teams"] = teams;
    std::ofstream of(hPath);
    of << handball.dump(); 
    of.close(); 
}

void FileHandler::writeFacility(Facility changedFacility)
{
    std::vector<FootballTeam*> ft;
    std::vector<BasketballTeam*> bt;
    std::vector<HandballTeam*> ht;
    for (size_t i = 0; i < changedFacility.size(); i++)
    {
        if (FootballTeam* fbt = dynamic_cast<FootballTeam*>(changedFacility[i]))
        {
            ft.push_back(fbt);
        }
        else if (BasketballTeam* bbt = dynamic_cast<BasketballTeam*>(changedFacility[i]))
        {
            bt.push_back(bbt);
        }
        else if (HandballTeam* hbt = dynamic_cast<HandballTeam*>(changedFacility[i]))
        {
            ht.push_back(hbt);
        }
    }
    writeFootballTeam(ft);
    writeBasketballTeam(bt);
    writeHandballTeam(ht);
}