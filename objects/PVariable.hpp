//
// Created by survari on 14.11.16.
//

#ifndef TEST_PVARIABLE_HPP
#define TEST_PVARIABLE_HPP

#include <iostream>

class PVariable
{
private:
    std::string name;
public:
    std::string getName()
    {
        return name;
    }

    void setName(std::string s)
    {
        name = s;
    }
};


#endif //TEST_PVARIABLE_HPP
