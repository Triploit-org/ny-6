//
// Created by survari on 13.11.16.
//

#ifndef TEST_INPUT_HPP
#define TEST_INPUT_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../Variables.hpp"
#include "../CPPSource.hpp"
#include "../StringCheck.hpp"

void input_variable(std::vector<std::string> args)
{
    std::string name = args[1];
    bool iint;

    if (Variables.existsIntegerVariable(name))
    {
        iint = true;
    }
    else if (Variables.existsStringVariable(name))
    {
        iint = false;
    }
    else
    {
        std::cout << "[ MAIN ]:[ INP ]:[ VARIABLE_NOT_FOUND:" << name << " ] Variable nicht gefunden!" << std::endl;
        exit(0);
    }

    if (iint)
    {
        int i;
        if (!Variables.isCpp())
            std::cin >> i;

        CPPSource.addSource("std::cin >> " + name);
        Variables.setIntegerVariable(name, i);
        // std::cout << Variables.getIntegerVariable(name).getName() << " == " << Variables.getIntegerVariable(name).getIntValue() << std::endl;
    }
    else
    {
        std::string str;
        if (!Variables.isCpp())
            std::getline(std::cin, str);

        CPPSource.addSource("std::getline(std::cin, " + name + ")");

        Variables.setStringVariable(name, str);
    }
}

#endif //TEST_INPUT_HPP
