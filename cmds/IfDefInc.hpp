//
// Created by survari on 14.11.16.
//

#ifndef TEST_IFDEFINC_HPP
#define TEST_IFDEFINC_HPP

#include <iostream>
#include <vector>
#include "../objects/PVariable.hpp"
#include "../PraeVars.hpp"

void include_file(std::vector<std::string> args)
{

}

void prae_ifndef(std::vector<std::string> args)
{

}

void prae_ifdef(std::vector<std::string> args)
{

}

void prae_define(std::vector<std::string> args)
{
    std::string name = args[1];
    PVariable p;
    p.setName(name);

    if (PraeVars.existsVar(name))
    {
        std::cout << "[ MAIN ]:[ PRAE ]:[ DEF ]:[ ALREADY_DFINED:" << name << " ] Variable schon deklariert!" << std::endl;
        exit(0);
    }
    else
    {
        PraeVars.addPVar(p);
    }
}

void prae_undef(std::vector<std::string> args)
{
    std::string name = args[1];

    if (!PraeVars.existsVar(name))
    {
        std::cout << "[ MAIN ]:[ PRAE ]:[ DEF ]:[ NOT_DFINED:" << name << " ] Variable nicht deklariert!"
                  << std::endl;
        exit(0);
    }
    else
    {
        PraeVars.removePVar(name);
    }

}

void prae_error(std::vector<std::string> args)
{
    std::string arg = args[1];

    if (arg.substr(0, 1) == "\"" && arg.substr(arg.length()-1, arg.length()-2) == "\"")
    {
        std::cout << "[ MAIN ]:[ ERROR ] " << arg.substr(1, arg.length()-2) << std::endl;
    }
    else
    {
        std::cout << "[ MAIN ]:[ ERROR ] " << arg << std::endl;
    }
}

#endif //TEST_IFDEFINC_HPP
