//
// Created by survari on 06.11.16.
//

#ifndef TEST_VARIABLES_HPP
#define TEST_VARIABLES_HPP

#include <vector>
#include "String.hpp"
#include "Integer.hpp"

class Variables
{
private:
    std::vector<String> strings;
    std::vector<Integer> integer;

    bool iscpp = false;

public:
    bool isCpp()
    {
        return iscpp;
    }

    void setCpp(bool b)
    {
        iscpp = b;
    }

    void initStrings()
    {
        String snull;
        snull.setName("_SN");

        snull.setStringValue("");
        snull.setWriteAble(false);

        strings.push_back(snull);
    }

    void initInteger()
    {
        Integer inull;
        inull.setName("_IN");

        inull.setIntValue(0);
        inull.setWriteAble(false);

        integer.push_back(inull);
    }

    bool existsStringVariable(std::string name)
    {
        for (int i = 0; i < strings.size(); i++)
        {
            if (strings[i].getName() == name)
            {
                return true;
            }
        }
        return false;
    }

    bool existsIntegerVariable(std::string name)
    {
        for (int i = 0; i < integer.size(); i++)
        {
            if (integer[i].getName() == name)
            {
                return true;
            }
        }
        return false;
    }

    String getStringVariable(std::string name)
    {
        for (int i = 0; i < strings.size(); i++)
        {
            if (strings[i].getName() == name)
            {
                return strings[i];
            }
        }

        std::cout << "[ MAIN ]:[ VARSYS:STR ]:[ NOT_FOUND:" << name << " ] String-Variable nicht gefunden!" << std::endl;

        String str;
        str.setName("[NotFound]");
        str.setStringValue("[NotFound]");
        return str;
    }

    void setStringVariable(std::string name, std::string value)
    {
        for (int i = 0; i < strings.size(); i++)
        {
            if (strings[i].getName() == name)
            {
                strings[i].setStringValue(value);
                //std::cout << "NAME >> " << strings[i].getStringValue() << std::endl;
            }
        }
    }

    Integer getIntegerVariable(std::string name)
    {
        for (int i = 0; i < integer.size(); i++)
        {
            if (integer[i].getName() == name)
            {
                return integer[i];
            }
        }

        std::cout << "[ MAIN ]:[ VARSYS:INT ]:[ NOT_FOUND:" << name << " ] Integer-Variable nicht gefunden!" << std::endl;

        Integer it;
        it.setName("[NotFound]");
        it.setIntValue(-23);
        return it;
    }

    void setIntegerVariable(std::string name, int value)
    {
        for (int j = 0; j < integer.size(); j++)
        {
            if (integer[j].getName() == name)
            {
                integer[j].setIntValue(value);
            }
        }
    }

    void addString(String s)
    {
        strings.push_back(s);
    }

    void addInteger(Integer i)
    {
        integer.push_back(i);
    }

    bool checkGoto(std::string g)
    {
    }
} Variables;

#endif //TEST_VARIABLES_HPP
