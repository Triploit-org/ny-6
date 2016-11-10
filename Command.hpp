//
// Created by survari on 06.11.16.
//

#include <iostream>
#include <vector>

#ifndef TEST_COMMAND_HPP
#define TEST_COMMAND_HPP

class Command
{
private:
    std::string name;
    int argc;
    void (*func)(std::vector<std::string> s);

public:
    std::string getName()
    {
        return name;
    }

    int getArgCount()
    {
        return argc;
    }

    void runFunction(std::vector<std::string> s)
    {
        func(s);
    }

    void setName(std::string s)
    {
        name = s;
    }

    void setArgCount(int a)
    {
        argc = a;
    }

    void setFunction(void (*foo)(std::vector<std::string> s))
    {
        func = foo;
    }

};

#endif //TEST_COMMAND_HPP
