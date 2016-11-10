//
// Created by survari on 06.11.16.
//


#ifndef TEST_STRING_HPP
#define TEST_STRING_HPP

#include <iostream>
#include <stdlib.h>

class String
{
private:
    std::string value;
    std::string name;
    bool isw = true;

public:
    std::string getStringValue()
    {
        return value;
    }

    std::string getName()
    {
        return name;
    }

    bool isWriteAble()
    {
        return isw;
    }

    void setStringValue(std::string val)
    {
        if (isWriteAble())
        {
            value = val;
        }
        else
        {
            std::cout << "[ MAIN ]:[ SYS ]:[ STRING ]:[ VARIABLE_NOT_WRITEABLE:" << name << " ] Variable ist nicht beschreibbar!" << std::endl;
            exit(0);
        }
      }

    void setName(std::string n)
    {
        name = n;
    }

    void setWriteAble(bool b)
    {
        isw = b;
    }
};


#endif //TEST_STRING_HPP
