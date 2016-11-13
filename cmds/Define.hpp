//
// Created by survari on 06.11.16.
//


#ifndef TEST_DEFINE_HPP
#define TEST_DEFINE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "../Variables.hpp"
#include "../CPPSource.hpp"

void define_string(std::vector<std::string> args)
{
    //std::cout << ">> DEFS gefunden!" << std::endl;

    std::string value = args[2];
    std::string name = args[1];

    if (Variables.existsStringVariable(name) || Variables.existsIntegerVariable(name))
    {
        std::cout << "[ MAIN ]:[ DEFS ]:[ REDEFINITION_OF:" << name << " ] Variable bereits deklariert!" << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        CPPSource.addSource("std::string "+name+" = "+value);
        value = value.substr(1, value.length() - 2);
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            std::cout << "[ MAIN ]:[ DEFS ]:[ VALUE_IS_INTEGER ] Die angegebene Variable beinhaltet eine Zahl!"
                      << std::endl;
            exit(0);
        }

        if (!Variables.existsStringVariable(value))
        {
            std::cout << "[ MAIN ]:[ DEFS ]:[ VALUE_NOT_FOUND:" << value
                      << " ] Die angegebene Variable existiert nicht!" << std::endl;
            exit(0);
        }
        else
        {
            CPPSource.addSource("std::string " + name + " = " + Variables.getStringVariable(value).getName());
            value = Variables.getStringVariable(value).getStringValue();
        }
    }

    String s;
    s.setName(name);
    s.setStringValue(value);

    s.setWriteAble(true);
    Variables.addString(s);
}

void define_int(std::vector<std::string> args)
{
    std::string Nvalue = args[2];
    std::string name = args[1];
    int value = 0;

    if (Variables.existsStringVariable(name) || Variables.existsIntegerVariable(name))
    {
        std::cout << "[ MAIN ]:[ DEFI ]:[ REDEFINITION_OF:" << name << " ] Variable bereits deklariert!" << std::endl;
        exit(0);
    }

    // std::cout << ">> DEFI gefunden! " << Nvalue << name << std::endl;

    if (Nvalue.substr(0, 1) == "\"" && Nvalue.substr(Nvalue.length() - 1, Nvalue.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ DEFI ]:[ VALUE_IS_INTEGER:" + Nvalue + " ] Der angegebene Wert ist ein String!"
                  << std::endl;
        exit(0);
    }
    else if (Nvalue.substr(0, 1) == "[" && Nvalue.substr(Nvalue.length() - 1, Nvalue.length() - 2) == "]")
    {
        value = std::stoi(Nvalue.substr(1, Nvalue.length() - 2));
        CPPSource.addSource("int " + name + " = " + std::to_string(value));
    }
    else
    {
        if (Variables.existsStringVariable(Nvalue))
        {
            std::cout << "[ MAIN ]:[ DEFI ]:[ VALUE_IS_STRING:" + Nvalue +
                         " ] Die angegebene Variable beinhaltet einen String!"
                      << std::endl;
            exit(0);
        }

        if (!Variables.existsIntegerVariable(Nvalue))
        {
            std::cout << "[ MAIN ]:[ DEFI ]:[ VALUE_NOT_FOUND:" << Nvalue
                      << " ] Die angegebene Variable existiert nicht!" << std::endl;
            exit(0);
        }
        else
        {
            value = Variables.getIntegerVariable(Nvalue).getIntValue();
            CPPSource.addSource("int " + name + " = " + Variables.getIntegerVariable(Nvalue).getName());
        }
    }

    Integer s;
    s.setName(name);
    s.setIntValue(value);

    s.setWriteAble(true);
    Variables.addInteger(s);
}

#endif //TEST_DEFINE_HPP
