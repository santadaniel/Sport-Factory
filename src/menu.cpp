#include "../headers/menu.hpp"

State Menu::state = Football;

void Menu::setState(const State& newState) 
{
    state = newState;
}

State Menu::getState() const
{
    return state;
}

std::ostream& Menu::print(std::ostream& os)
{   
    os << "Please select and option" << "\n";
    for (size_t i = 0; i < buttons.size(); i++)
    {
        os << i + 1 << ") " << buttons[i] << "\n";
    }
    os << "\n";
    return os;
}

size_t Menu::select(std::istream& is)
{
    size_t selectedButton = 0;
    is >> selectedButton;
    while (selectedButton == 0 || selectedButton > buttons.size())
    {
        std::cout << "Please select a correct option" << "\n";
        is >> selectedButton;
    }
    return selectedButton;
}

void MenuHandler::addMenu(Menu newMenu)
{
    menus.push_back(newMenu);
}

void MenuHandler::changeMenu(Menu oldMenu, Menu newMenu)
{
    menus.pop_back();
    addMenu(newMenu);
}

void MenuHandler::toPrevMenu()
{
    currentMenuIndex--;
}

void MenuHandler::toNextMenu()
{
    currentMenuIndex++;
}

size_t MenuHandler::getIndex() const
{
    return currentMenuIndex;
}

std::ostream& MenuHandler::print(std::ostream& os)
{
    return menus[currentMenuIndex].print(os);
}

size_t MenuHandler::select(std::istream& is)
{
    return menus[currentMenuIndex].select(is);
}

void MenuHandler::setState(const State& n)
{
    menus[currentMenuIndex].setState(n);
}

State MenuHandler::getState() const
{
    return menus[currentMenuIndex].getState();
}

Menu& MenuHandler::operator[](size_t i)
{
    return menus[i];
}
