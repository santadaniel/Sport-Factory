#include "../headers/person.hpp"

std::string Person::getName() const
{
    return name;
}

size_t Person::getAge() const
{
    return age;
}

bool Person::operator==(const Person& person) const
{
    return (name == person.name && age == person.age);
}

bool Person::operator!=(const Person& person) const
{
    return (name != person.name || age != person.age);
}