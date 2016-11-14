//
// Created by survari on 14.11.16.
//

#ifndef TEST_PRAEVARS_HPP
#define TEST_PRAEVARS_HPP


#include <vector>
#include <iostream>
#include <stdlib.h>
#include "objects/PVariable.hpp"

class PraeVars
{
private:
    std::vector<PVariable> pvars;

public:
    void addPVar(PVariable p)
    {
        pvars.push_back(p);
    }

    void removePVar(std::string name)
    {
        for (int i = 0; i < pvars.size(); i++)
        {
            if (pvars[i].getName() == name)
            {
                pvars.erase(pvars.begin()+i);
                return;
            }
        }

        std::cout << "[ MAIN ]:[ PRAE ]:[ UNDEF ]:[ VARIABLE_NOTFOUND:" << name << " ] Praeprozessorvariable nicht gefunden!" << std::endl;
        exit(0);
    }

    bool existsVar(std::string name)
    {
        for (int i = 0; i < pvars.size(); i++)
        {
            if (pvars[i].getName() == name)
            {
                return true;
            }
        }
        return false;
    }
} PraeVars;


#endif //TEST_PRAEVARS_HPP
