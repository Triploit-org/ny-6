//
// Created by survari on 08.11.16.
//

#ifndef TEST_GOTOS_HPP
#define TEST_GOTOS_HPP

#include <iostream>
#include <vector>
#include "objects/Goto.hpp"
#include "Variables.hpp"

class Gotos
{
private:
    std::vector<Goto> gotos;
    std::vector<Goto> labels;
    std::vector<int> goto_index;
    std::string aktgoto;
    int i;

    std::vector<int> lj;
    std::vector<std::string> lm;
    int line = 1;

public:
    std::string getAktGoto()
    {
        return aktgoto;
    }

    void setAktGoto(std::string n)
    {
        aktgoto = n;
    }

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
        int r = lj[lj.size()-1];
        //std::cout << "\t>> " << r << std::endl;
        lj.erase(lj.end()-1);

        for (int i = lj.size(); i > lm.size(); lm.erase(lm.end()-1)) {} // Buganfällig?

        return r;
    }

    std::string getLM()
    {
        std::string l = lm[lm.size()-1];
        lm.erase(lm.end()-1);

        for (int i = lm.size(); i > lj.size(); lj.erase(lj.end()-1)) {} // Buganfällig?

        return l;
    }

    void addLJ(int l)
    {
       // std::cout << "ADDI: " << l << std::endl;
        lj.push_back(l);
        lm.push_back(aktgoto);
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
                return true;
            }
        }

        return false;
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
