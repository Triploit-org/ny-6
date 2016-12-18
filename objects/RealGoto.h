//
// Created by survari on 18.12.16.
//

#ifndef TEST_REALGOTO_H
#define TEST_REALGOTO_H

#include <iostream>

class RealGoto
{
private:
    std::string name;
    int index;

public:
    RealGoto()
    {}

    RealGoto(std::string nm, int ind)
    {
        name = nm;
        index = ind;
    }

    std::string getName()
    {
        return name;
    }

    int getIndex()
    {
        return index;
    }

    void setName(std::string s)
    {
        name = s;
    }

    void setIndex(int i)
    {
        index = i;
    }
};


#endif //TEST_REALGOTO_H
