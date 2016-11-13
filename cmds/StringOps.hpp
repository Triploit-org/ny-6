//
// Created by survari on 06.11.16.
//

#ifndef TEST_STRINGOPS_HPP
#define TEST_STRINGOPS_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../Variables.hpp"
#include "../CPPSource.hpp"

void sti_int(std::vector<std::string> args)
{
    std::string name = args[1]; // INPUT   INT
    std::string ovar = args[2]; // OUTPUT  STRING

    if (Variables.existsIntegerVariable(ovar))
    {
        std::cout << "[ MAIN ]:[ STI ]:[ VARIABLE_HAS_INVALID_TYPE:" << ovar << " ] Die zweite Variable muss vom Typen String sein!" << std::endl;
        exit(0);
    }

    if (Variables.existsStringVariable(name))
    {
        std::cout << "[ MAIN ]:[ STI ]:[ VARIABLE_HAS_INVALID_TYPE:" << name << " ] Die erste Variable muss vom Typen Integer sein!" << std::endl;
        exit(0);
    }

    if (!Variables.existsIntegerVariable(name))
    {
        std::cout << "[ MAIN ]:[ STI ]:[ VARIABLE_NOT_FOUND:" << name << " ] Integer-Variable nicht gefunden!" << std::endl;
        exit(0);
    }

    if (!Variables.existsStringVariable(ovar))
    {
        std::cout << "[ MAIN ]:[ STI ]:[ VARIABLE_NOT_FOUND:" << ovar << " ] String-Variable nicht gefunden!" << std::endl;
        exit(0);
    }

    std::string val;
    val = (char) Variables.getIntegerVariable(name).getIntValue();

    Variables.setStringVariable(ovar, val);
    CPPSource.addSource(ovar + " = (char) "+name);
}

void gca_string(std::vector<std::string> args)
{
    std::string name = args[1];
    std::string index = args[2];
    std::string ovar = args[3];
    int iindex = 0;

    if (index.substr(0, 1) == "[" && index.substr(index.length() - 1, index.length() - 2) == "]")
    {
        iindex = std::stoi(index.substr(1, index.length() - 2));
    }
    else if (Variables.existsIntegerVariable(index))
    {
        iindex = Variables.getIntegerVariable(index).getIntValue();
    }
    else if (Variables.existsStringVariable(index))
    {
        std::cout << "[ MAIN ]:[ GCA ]:[ INVALID_VARIABLE_TYPE:" << index
                  << " ] Variable ist ein String, muss aber ein Integer sein!" << std::endl;
        exit(0);
    }
    else if (!Variables.existsIntegerVariable(index))
    {
        std::cout << "[ MAIN ]:[ GCA ]:[ (2) VARIABLE_NOT_FOUND:" << index << " ] Variable nicht gefunden!" << std::endl;
        exit(0);
    }

    if (!Variables.existsStringVariable(name))
    {
        std::cout << "[ MAIN ]:[ GCA ]:[ (1) VARIABLE_NOT_FOUND:" << name << " ] Variable nicht gefunden!" << std::endl;
        exit(0);
    }

    if (!Variables.existsStringVariable(ovar))
    {
        std::cout << "[ MAIN ]:[ GCA ]:[ (3) VARIABLE_NOT_FOUND:" << ovar << " ] Variable nicht gefunden!" << std::endl;
        exit(0);
    }

    CPPSource.addSource(ovar + " = " + name + "[" + std::to_string(iindex) + "]");
    std::string val;

    val = Variables.getStringVariable(name).getStringValue()[iindex];
    Variables.setStringVariable(ovar, val);
}
#endif //TEST_STRINGOPS_HPP
