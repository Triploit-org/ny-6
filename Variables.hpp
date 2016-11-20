//
// Created by survari on 06.11.16.
//

#ifndef TEST_VARIABLES_HPP
#define TEST_VARIABLES_HPP

#include <vector>
#include "objects/String.hpp"
#include "objects/Integer.hpp"
#include "objects/Scope.hpp"

class Variables
{
private:
    std::vector<Scope> scopes;
    Scope aktscope;

    bool iscpp = false;
    int line = 1;

public:
    void listScopes()
    {
        for (int i = 0; i < scopes.size(); i++)
        {
            std::cout << scopes[i].getName() << std::endl;

            for (int j = 0; j < scopes[i].getIntegers().size(); j++)
            {
                std::cout << "\tINT:" << scopes[i].getIntegers()[j].getName() << std::endl;
            }

            std::cout << std::endl;

            for (int j = 0; j < scopes[i].getStrings().size(); j++)
            {
                std::cout << "\tSTR:" << scopes[i].getStrings()[j].getName() << std::endl;
            }
        }
    }

    void addLineCount()
    {
        line = line + 1;
    }

    int getLine()
    {
        return line;
    }

    std::vector<Scope> getScopes()
    {
        return scopes;
    }

    void addScope(Scope s)
    {
        scopes.push_back(s);
    }

    bool isCpp()
    {
        return iscpp;
    }

    void setCpp(bool b)
    {
        iscpp = b;
    }

    Scope getAktScope()
    {
        return aktscope;
    }

    Scope getScope(std::string n)
    {
        for (int i = 0; i < scopes.size(); i++)
        {
            if (scopes[i].getName() == n)
            {
                return scopes[i];
            }
        }

        std::cout << "[ MAIN ]:[ SYS ]:[ FATAL ]:[ SCOPE_NOT_FOUND:" << n << " ] Bereich nicht gefunden!" << std::endl;
    }

    void setAktScope(Scope s)
    {
        for (int i = 0; i < scopes.size(); i++)
        {
            if (scopes[i].getName() == aktscope.getName())
            {
                scopes[i].setIntegers(aktscope.getIntegers());
                scopes[i].setStrings(aktscope.getStrings());
            }
        }

        aktscope = s;
        //std::cout << "SET SCOPE TO >> " << s.getName() << std::endl;
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


        aktscope.addStr(snull);
        aktscope.addStr(axs);
        aktscope.addStr(bxs);
        aktscope.addStr(cxs);
        aktscope.addStr(dxs);
        aktscope.addStr(exs);
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

        aktscope.addInt(inull);
        aktscope.addInt(axi);
        aktscope.addInt(bxi);
        aktscope.addInt(cxi);
        aktscope.addInt(dxi);
        aktscope.addInt(exi);
    }

    bool existsStringVariable(std::string name)
    {
        for (int i = 0; i < aktscope.getStrings().size(); i++)
        {
            if (aktscope.getStrings()[i].getName() == name)
            {
                return true;
            }
        }

        Scope p = getScope("public__aXX");
        for (int i = 0; i < p.getStrings().size(); i++)
        {
            if (p.getStrings()[i].getName() == name)
            {
                return true;
            }
        }
        return false;
    }

    bool existsIntegerVariable(std::string name)
    {
        for (int i = 0; i < aktscope.getIntegers().size(); i++)
        {
            if (aktscope.getIntegers()[i].getName() == name)
            {
                return true;
            }
        }

        Scope p = getScope("public__aXX");
        for (int i = 0; i < p.getIntegers().size(); i++)
        {
            if (p.getIntegers()[i].getName() == name)
            {
                return true;
            }
        }
        return false;
    }

    String getStringVariable(std::string name)
    {
        for (int i = 0; i < aktscope.getStrings().size(); i++)
        {
            if (aktscope.getStrings()[i].getName() == name)
            {
                return aktscope.getStrings()[i];
            }
        }

        Scope p = getScope("public__aXX");
        for (int i = 0; i < p.getStrings().size(); i++)
        {
            if (p.getStrings()[i].getName() == name)
            {
                // std::cout << "!! GETSTRING " << name << " == " << p.getStrings()[i].getName() << std::endl;
                return p.getStrings()[i];
            }
            // std::cout << "GETSTRING " << name << " != " << p.getStrings()[i].getName() << std::endl;
        }

        std::cout << "[ MAIN ]:[ VARSYS:STR ]:[ NOT_FOUND:" << name << " ] String-Variable nicht gefunden!"
                  << std::endl;

        String str;
        str.setName("[NotFound]");
        str.setStringValue("[NotFound]");
        return str;
    }

    void setStringVariable(std::string name, std::string value)
    {
        for (int i = 0; i < aktscope.getStrings().size(); i++)
        {
            if (aktscope.getStrings()[i].getName() == name)
            {
                aktscope.setStr(name, value);
                //std::cout << "NAME >> " << aktscope.getStrings()[i].getStringValue() << std::endl;
            }
        }

        for (int i = 0; i < scopes.size(); i++)
        {
            if (scopes[i].getName() == "public__aXX")
            {
                scopes[i].setStr(name, value);
            }
        }
    }

    Integer getIntegerVariable(std::string name)
    {
        for (int i = 0; i < aktscope.getIntegers().size(); i++)
        {
            if (aktscope.getIntegers()[i].getName() == name)
            {
                return aktscope.getIntegers()[i];
            }
        }

        Scope p = getScope("public__aXX");
        for (int i = 0; i < p.getIntegers().size(); i++)
        {
            if (p.getIntegers()[i].getName() == name)
            {
                return p.getIntegers()[i];
            }
        }

        std::cout << "[ MAIN ]:[ VARSYS:STR ]:[ NOT_FOUND:" << name << " ] String-Variable nicht gefunden!"
                  << std::endl;

        Integer str;
        str.setName("[NotFound]");
        str.setIntValue(-999);
        return str;
    }

    void setIntegerVariable(std::string name, int value)
    {
        for (int i = 0; i < aktscope.getStrings().size(); i++)
        {
            if (aktscope.getStrings()[i].getName() == name)
            {
                aktscope.setInt(name, value);
                //std::cout << "NAME >> " << aktscope.getStrings()[i].getStringValue() << std::endl;
            }
        }

        for (int i = 0; i < scopes.size(); i++)
        {
            if (scopes[i].getName() == "public__aXX")
            {
                scopes[i].setInt(name, value);
            }
        }
    }

    void addString(String s)
    {
        aktscope.addStr(s);
        //std::cout << " ADD:STR >> " << s.getName() << std::endl;
    }

    void addInteger(Integer i)
    {
        aktscope.addInt(i);
        //std::cout << " ADD:INT >> " << i.getName() << std::endl;
    }

    bool checkGoto(std::string g)
    {
    }

    std::vector<Integer> getIntegerVariables()
    {
        return aktscope.getIntegers();
    }

    std::vector<String> getStringVariables()
    {
        return aktscope.getStrings();
    }

} Variables;

#endif //TEST_VARIABLES_HPP
