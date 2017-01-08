//
// Created by survari on 06.11.16.
//

#ifndef TEST_GOTO_HPP
#define TEST_GOTO_HPP

#include <iostream>

class Goto
{
private:
    std::string name;
    int index;

    bool isclosed = false;
    bool isadefined = false;

public:
    std::string getName()
    {
        return name;
    }

    int getIndex()
    {
        return index;
    }

    bool isClosed()
    {
        return isclosed;
    }

    bool isAlreadyDefined()
    {
        return isadefined;
    }

    void setName(std::string s)
    {
        name = s;
    }

    void setIndex(int i)
    {
        index = i;
    }

    void setClosed(bool b)
    {
        isclosed = b;
    }

    void setAlreadyDefined(bool b)
    {
        isadefined = b;
    }
};


#endif //TEST_GOTO_HPP
