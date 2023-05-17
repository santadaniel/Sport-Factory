#include "headers/menu.hpp"
#include "headers/file.hpp"

int main()
{
    FileHandler fileHandler("data/footballTeam.json", "data/basketballTeam.json", "data/handballTeam.json");

    Facility facility = fileHandler.readFacility();

    bool isQuit = false;
    Menu menu1({"Football teams", "Basketball teams", "Handball teams", "Quit"});
    Menu menu2({"List teams", "Add a team", "Remove a team", "Back", "Quit"});
    Menu menu3Football({"Add a Player", "Remove a player",
                    "Add a coach", "Remove a coach",
                    "Back", "Quit"});
    Menu menu3Basketball({"Add a Player", "Remove a player",
                    "Add a cheerleader", "Remove a cheerleader",
                    "Back", "Quit"});
    Menu menu3Handball({"Add a Player", "Remove a player",
                    "Change the current yearly support money value",
                    "Set current yearly support money value to $0",
                    "Back", "Quit"});
    MenuHandler menuHandler({menu1, menu2, menu3Football});
    while (!isQuit)
    {
        menuHandler.print(std::cout);
        size_t n = menuHandler.select(std::cin);
        switch (menuHandler.getIndex())  //State machine for the menu
        {
            case 0:
                switch (n)
                {
                    case 1:
                        menuHandler.setState(Football);
                        menuHandler.changeMenu(menuHandler[2], menu3Football);
                        menuHandler.toNextMenu();
                    break;
                    case 2:
                        menuHandler.setState(Basketball);
                        menuHandler.changeMenu(menuHandler[2], menu3Basketball);
                        menuHandler.toNextMenu();
                    break;
                    case 3:
                        menuHandler.setState(Handball);
                        menuHandler.changeMenu(menuHandler[2], menu3Handball);
                        menuHandler.toNextMenu();
                    break;
                    default:
                        isQuit = true;
                    break;
                }
            break;
            case 1:
                switch (n)
                {
                    case 1:
                        if (menuHandler.getState() == Football)
                        {
                            facility.listFootballTeams(std::cout);
                        }
                        if (menuHandler.getState() == Basketball)
                        {
                            facility.listBasketballTeams(std::cout);
                        }
                        if (menuHandler.getState() == Handball)
                        {
                            facility.listHandballTeams(std::cout);
                        }
                        std::cout << "Select a team for changes." << "\n" << "-1) Quit\n-2) Back\n";
                        int select;
                        std::cin >> select;
                        if (select == -1)
                        {
                            isQuit = true;
                        }                       
                        if (select != -1 && select != -2)
                        {
                            while (!facility.setCurrentTeam(select))
                            {
                                std::cin >> select;
                            }
                            menuHandler.toNextMenu();
                        }
                    break;
                    case 2:
                    {
                        std::string teamName;
                        std::cout << "Please enter the team's name." << "\n";
                        std::cin >>  teamName;
                        if (menuHandler.getState() == Football)
                        {
                            FootballTeam* newTeam = new FootballTeam(teamName);
                            if(!facility.addTeam(newTeam))
                            {
                                std::cout << "This team is already in the facility.";
                                delete newTeam;
                            }
                        }
                        if (menuHandler.getState() == Basketball)
                        {
                            BasketballTeam* newTeam = new BasketballTeam(teamName);
                            if(!facility.addTeam(newTeam))
                            {
                                std::cout << "This team is already in the facility.";
                                delete newTeam;
                            }
                        }
                        if (menuHandler.getState() == Handball)
                        {
                            HandballTeam* newTeam = new HandballTeam(teamName);
                            if(!facility.addTeam(newTeam))
                            {
                                std::cout << "This team is already in the facility.";
                                delete newTeam;
                            }
                        }
                    break;
                    }
                    case 3:
                    {
                        std::string teamName;
                        std::cout << "Please enter the team's name." << "\n";
                        std::cin >>  teamName;
                        Team oldTeam(teamName);
                        if(!facility.removeTeam(oldTeam))
                            std::cout << "This team is not in the facility.";
                    break;
                    }
                    case 4:
                        menuHandler.toPrevMenu();
                    break;
                    default:
                        isQuit = true;
                    break;
                }
            break;       
            case 2:
                switch (n)
                {
                    case 1:
                    {
                        std::string name;
                        size_t age;
                        bool error = false;
                        std::cout << "Please enter the player's name and age.\n";
                        std::cin >> name >> age;
                        if (menuHandler.getState() == Football)
                        {
                            error = !facility.getTeam<FootballTeam>(facility.getCurrentTeam())->addPlayer(Person(name, age));
                        }
                        if (menuHandler.getState() == Basketball)
                        {
                            error = !facility.getTeam<BasketballTeam>(facility.getCurrentTeam())->addPlayer(Person(name, age));
                        }
                        if (menuHandler.getState() == Handball)
                        {
                            error = !facility.getTeam<HandballTeam>(facility.getCurrentTeam())->addPlayer(Person(name, age));
                        }
                        if (error)
                        {
                            std::cout << "This player is already in the team.\n";
                        }
                    break;
                    }
                    case 2:
                    {
                        std::string name;
                        size_t age;
                        bool error = false;
                        std::cout << "Please enter the player's name and age.\n";
                        std::cin >> name >> age;
                        if (menuHandler.getState() == Football)
                        {
                            error = !facility.getTeam<FootballTeam>(facility.getCurrentTeam())->removePlayer(Person(name, age));
                        }
                        if (menuHandler.getState() == Basketball)
                        {
                            error = !facility.getTeam<BasketballTeam>(facility.getCurrentTeam())->removePlayer(Person(name, age));
                        }
                        if (menuHandler.getState() == Handball)
                        {
                            error = !facility.getTeam<HandballTeam>(facility.getCurrentTeam())->removePlayer(Person(name, age));
                        }
                        if (error)
                        {
                            std::cout << "This player is not in the team\n";
                        }
                    break;
                    }
                    case 3:
                    {
                        std::string name;
                        size_t age;
                        size_t newValue;
                        bool error = false;
                        if (menuHandler.getState() == Football)
                        {
                            std::cout << "Please enter the coach's name and age.\n";
                            std::cin >> name >> age;
                            error = !facility.getTeam<FootballTeam>(facility.getCurrentTeam())->addCoach(Person(name, age));
                            if (error)
                            {
                                std::cout << "This coach is already in the team, or you already have 2 coaches.\n";
                            }
                        }
                        if (menuHandler.getState() == Basketball)
                        {
                            std::cout << "Please enter the cheerleader's name and age.\n";
                            std::cin >> name >> age;
                            error = !facility.getTeam<BasketballTeam>(facility.getCurrentTeam())->addCheerleader(Person(name, age));
                            if (error)
                            {
                                std::cout << "This cheerleader is already in the team.\n";
                            }
                        }
                        if (menuHandler.getState() == Handball)
                        {
                            std::cout << "Please enter the new value of the yearly support money.\n";
                            std::cin >> newValue;
                            facility.getTeam<HandballTeam>(facility.getCurrentTeam())->changeSupportMoney(newValue);
                        }
                    break;
                    }
                    case 4:
                        {
                        std::string name;
                        size_t age;
                        bool error = false;
                        if (menuHandler.getState() == Football)
                        {
                            std::cout << "Please enter the coach's name and age.\n";
                            std::cin >> name >> age;
                            error = !facility.getTeam<FootballTeam>(facility.getCurrentTeam())->removeCoach(Person(name, age));
                            if (error)
                            {
                                std::cout << "This coach is not in the team.\n";
                            }
                        }
                        if (menuHandler.getState() == Basketball)
                        {
                            std::cout << "Please enter the cheerleader's name and age.\n";
                            std::cin >> name >> age;
                            error = !facility.getTeam<BasketballTeam>(facility.getCurrentTeam())->removeCheerleader(Person(name, age));
                            if (error)
                            {
                                std::cout << "This cheerleader is not in the team.\n";
                            }
                        }
                        if (menuHandler.getState() == Handball)
                        {
                            facility.getTeam<HandballTeam>(facility.getCurrentTeam())->changeSupportMoney(0);
                        }
                    break;
                    }
                    case 5:
                        menuHandler.toPrevMenu();
                    break;
                    case 6:
                        isQuit = true;
                    break;
                }
            break;
        }
    }
    fileHandler.writeFacility(facility);

    return 0;
}