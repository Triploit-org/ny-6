//
// Created by survari on 06.11.16.
//

#ifndef TEST_VARIABLES_HPP
#define TEST_VARIABLES_HPP

#include <vector>
#include "objects/String.hpp"
#include "objects/Integer.hpp"

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

        String axs;
        axs.setName("_axs");
        axs.setStringValue("");
        axs.setWriteAble(true);

        String bxs;
        bxs.setName("_bxs");
        bxs.setStringValue("");
        bxs.setWriteAble(true);

        String cxs;
        bxs.setName("_cxs");
        bxs.setStringValue("");
        bxs.setWriteAble(true);

        String dxs;
        dxs.setName("_dxs");
        dxs.setStringValue("");
        dxs.setWriteAble(true);

        String exs;
        exs.setName("_exs");
        exs.setStringValue("");
        exs.setWriteAble(true);


        strings.push_back(snull);
        strings.push_back(axs);
        strings.push_back(bxs);
        strings.push_back(cxs);
        strings.push_back(dxs);
        strings.push_back(exs);
    }

    void initInteger()
    {
        Integer inull;
        inull.setName("_IN");
        inull.setIntValue(0);
        inull.setWriteAble(false);

        Integer axi;
        axi.setName("_axi");
        axi.setIntValue(0);
        axi.setWriteAble(true);

        Integer bxi;
        bxi.setName("_bxi");
        bxi.setIntValue(0);
        bxi.setWriteAble(true);

        Integer cxi;
        bxi.setName("_cxi");
        bxi.setIntValue(0);
        bxi.setWriteAble(true);

        Integer dxi;
        dxi.setName("_dxi");
        dxi.setIntValue(0);
        dxi.setWriteAble(true);

        Integer exi;
        exi.setName("_exi");
        exi.setIntValue(0);
        exi.setWriteAble(true);

        integer.push_back(inull);
        integer.push_back(axi);
        integer.push_back(bxi);
        integer.push_back(cxi);
        integer.push_back(dxi);
        integer.push_back(exi);
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

    std::vector<Integer> getIntegerVariables()
    {
        return integer;
    }

    std::vector<String> getStringVariables()
    {
        return strings;
    }

} Variables;

#endif //TEST_VARIABLES_HPP
