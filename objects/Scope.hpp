//
// Created by survari on 19.11.16.
//

#ifndef TEST_SCOPE_HPP
#define TEST_SCOPE_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "String.hpp"
#include "Integer.hpp"
#include "RealGoto.h"
#include "../Error.hpp"

class Scope
{
private:
    std::vector<String> strings;
    std::vector<Integer> integer;
    std::string scopename;
    std::vector<RealGoto> gotos;

public:
    void listItems()
    {
        std::cout << std::endl;
        for (int i = 0; i < strings.size(); i++)
        {
            std::cout << "[" << scopename << "][STR] " << strings[i].getName() << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < integer.size(); i++)
        {
            std::cout << "[" << scopename << "][INT] " << integer[i].getName() << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < gotos.size(); i++)
        {
            std::cout << "[" << scopename << "][RGT] " << gotos[i].getName() << std::endl;
        }
        std::cout << std::endl;
    }

    RealGoto getRealGoto(std::string name)
    {
        for (int i = 0; i < gotos.size(); i++)
        {
            if (gotos[i].getName() == name)
                return gotos[i];
        }

        return RealGoto("[NotFound]", -999);
    }

    bool existsRealGoto(std::string name)
    {
        for (int i = 0; i < gotos.size(); i++)
        {
            // std::cout << "EXGT? ]] " << gotos[i].getName() << " != " << name << std::endl;

            if (gotos[i].getName() == name)
                return true;
        }

        // std::cout << "EXGTI ]] "<< gotos.size() << std::endl;
        return false;
    }

    void addRealGoto(RealGoto rg)
    {
        if (existsRealGoto(rg.getName()) == false)
        {
            gotos.push_back(rg);
            // std::cout << "ADDGT ]] Add RealGoto to "<<scopename<<" >> " << rg.getName() << " AT " << rg.getIndex() << std::endl;
            return;
        }
        else
        {
            Error.printErr("[ MAIN ]:[ SYS ]:[ SCOPE:",scopename," ]:[ ALREADYEXISTSGOTO:", rg.getName(), " ] Goto existiert bereits!");
            exit(0);
        }
     }

    std::vector<RealGoto> getRealGotos()
    {
        return gotos;
    }

    void setRealGotos(std::vector<RealGoto> gs)
    {
        gotos = gs;
    }

    void setName(std::string s)
    {
        scopename = s;
    }

    void setIntegers(std::vector<Integer> i)
    {
        integer = i;
    }

    void setStrings(std::vector<String> s)
    {
        strings = s;
    }

    std::string getName()
    {
        return scopename;
    }

    std::vector<String> getStrings()
    {
        return strings;
    }

    std::vector<Integer> getIntegers()
    {
        return integer;
    }

    void addStr(String s)
    {
        strings.push_back(s);
    }

    void addInt(Integer i)
    {
        integer.push_back(i);
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

        std::cout << "[ MAIN ]:[ VARSYS:INT ]:[ NOT_FOUND:" << name << " IN " << scopename << " ] Integer-Variable nicht im Bereich gefunden!" << std::endl;
        exit(0);

        Integer it;
        it.setName("[NotFound]");
        it.setIntValue(-23);
        return it;
    }

    void setInt(std::string name, int value)
    {
        for (int j = 0; j < integer.size(); j++)
        {
            if (integer[j].getName() == name)
            {
                //std::cout << "SCOPE::" << scopename << " SETINT INT:" << name << " ==>> " << value << " ";
                integer[j].setIntValue(value);
                //std::cout << " == " << integer[j].getIntValue() << std::endl;
                return;
            }
        }
        std::cout << "[ MAIN ]:[ VARSYS:INT ]:[ SCOPE ]:[ NOT_FOUND:" << name << " IN " << scopename << "] Integer-Variable im Scope nicht gefunden!" << std::endl;
        exit(0);
    }

    void setStr(std::string name, std::string value)
    {
        for (int j = 0; j < strings.size(); j++)
        {
            if (strings[j].getName() == name)
            {
                // std::cout << scopename << " SETSTR STR:" << name << " = " << value << std::endl;
                strings[j].setStringValue(value);
                // std::cout << " == " << strings[j].getStringValue() << std::endl;
            }
        }
    }

    void clearVariables()
    {
        strings.clear();
        integer.clear();
        // gotos.clear();
    }
};


#endif //TEST_SCOPE_HPP
