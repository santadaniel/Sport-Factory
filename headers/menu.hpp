#ifndef MENU_HPP
#define MENU_HPP

#include "facility.hpp"

enum State
{
    Football,
    Basketball,
    Handball,
    Quit
};

class Menu
{
private:
    std::vector<std::string> buttons;
    static State state;
public:
    Menu(std::vector<std::string> buttons): buttons(buttons) {}

    void setState(const State& n);
    State getState() const;

    std::ostream& print(std::ostream& os);
    size_t select(std::istream& is);
};

class MenuHandler
{
private:
    std::vector<Menu> menus;
    size_t currentMenuIndex;
public:
    MenuHandler(std::vector<Menu> menus): menus(menus), currentMenuIndex(0) {}

    void addMenu(Menu newMenu);
    void changeMenu(Menu oldMenu, Menu newMenu);
    void toPrevMenu();
    void toNextMenu();
    size_t getIndex() const;
    void setState(const State& n);
    State getState() const;

    Menu& operator[](size_t i);

    std::ostream& print(std::ostream& os);
    size_t select(std::istream& is);
};

#endif
