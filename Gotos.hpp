//
// Created by survari on 08.11.16.
//

#ifndef TEST_GOTOS_HPP
#define TEST_GOTOS_HPP

#include <iostream>
#include <vector>
#include "objects/Goto.hpp"

class Gotos
{
private:
    std::vector<Goto> gotos;
    std::vector<Goto> labels;
    std::vector<int> goto_index;
    int i;
    int lj;
    int line = 1;

public:

    void addLineCount()
    {
        line = line + 1;
    }

    int getLine()
    {
        return line;
    }

    int getI()
    {
        return i;
    }

    void setI(int s)
    {
        i = s;
    }

    int getLJ()
    {
        return lj;
    }

    void setLJ(int l)
    {
        lj = l;
    }

    Goto getGoto(std::string name)
    {
        for (int i = 0; i < gotos.size(); i++)
        {
            if (name == gotos[i].getName())
            {
                return gotos[i];
            }
        }

        Goto g;
        g.setName("[NotFound]");

        g.setIndex(-999);
        return g;
    }

    std::vector<Goto> getGotos()
    {
        return gotos;
    }

    bool setGotoClosed(std::string name, bool b)
    {
        for (int i = 0; i < gotos.size(); i++)
        {
            if (name == gotos[i].getName())
            {
                gotos[i].setClosed(b);
            }
        }
    }

    bool findGoto(std::string name)
    {
        for (int i = 0; i < gotos.size(); i++)
        {
            if (name == gotos[i].getName())
            {
                return true;
            }
        }
        return false;
    }

    void addGoto(Goto s)
    {
        gotos.push_back(s);
    }
} Gotos;

#endif //TEST_GOTOS_HPP
