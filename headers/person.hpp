#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>

class Person
{
private:
    std::string name;
    size_t age;
public:
    Person(std::string name, size_t age): name(name), age(age) {}

    std::string getName() const;
    size_t getAge() const;
    bool operator==(const Person& person) const;
    bool operator!=(const Person& perror) const;
};

#endif