//
// Created by survari on 06.11.16.
//

#ifndef TEST_OUTPUT_HPP
#define TEST_OUTPUT_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../Variables.hpp"
#include "../CPPSource.hpp"

void print_value(std::vector<std::string> args)
{
    //std::cout << ">> PRV gefunden!" << std::endl;

    if (Variables.existsIntegerVariable(args[1]))
    {
        if (!Variables.isCpp())
            std::cout << Variables.getIntegerVariable(args[1]).getIntValue();
        CPPSource.addSource("std::cout << "+Variables.getIntegerVariable(args[1]).getName());
    }
    else if (Variables.existsStringVariable(args[1]))
    {
        if (!Variables.isCpp())
            std::cout << Variables.getStringVariable(args[1]).getStringValue();
        CPPSource.addSource("std::cout << "+Variables.getStringVariable(args[1]).getName());
    }
    else
    {
        std::cout << "[ MAIN ]:[ PRV ]:[ VALUE_NOT_FOUND:"<< args[1] <<" ] Die angegebene Variable existiert nicht!" << std::endl;
        exit(0);
    }
}

void say_text(std::vector<std::string> args)
{
    if ((args[1].substr(0, 1) == "\"" && args[1].substr(args[1].length() - 1, args[1].length() - 2) == "\"") || (args[1].substr(0, 1) == "[" && args[1].substr(args[1].length() - 1, args[1].length() - 2) == "]"))
    {
        if (!Variables.isCpp())
            std::cout << args[1].substr(1, args[1].length()-2);
        CPPSource.addSource("std::cout << \"" + args[1].substr(1, args[1].length()-2)+ "\"");
    }
    else
    {
        if (!Variables.isCpp())
            std::cout << args[1];
        CPPSource.addSource("std::cout << " + args[1]);
    }

    return;
}

#endif //TEST_OUTPUT_HPP
