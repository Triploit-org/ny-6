//
// Created by survari on 08.11.16.
//

#ifndef TEST_EQUALS_HPP
#define TEST_EQUALS_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../Variables.hpp"
#include "../CPPSource.hpp"
#include "../Gotos.hpp"

void equals_equals_int(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);
    char gtn1 = gtn.at(0);
    char gtn2 = ' ';
    gtn2 = gtn.at(gtn.length()-1);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ EQI ]:[ GOTO_NOT_FOUND:" << gtn << "||" << gtnaz << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;

        std::vector<RealGoto> rgs = Variables.getRealGotos();
        for (int i = 0; i < rgs.size(); i++)
        {
            std::cout << i << "/" << rgs.size()-1 << "]] " << rgs[i].getName() << std::endl;
        }
        std::cout << rgs.size();

        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ EQI ]:[ VARIABLE_IS_STRING ] Die Variable(\") ist ein String!" << std::endl;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            int v = Variables.getIntegerVariable(name).getIntValue();
            int v2 = std::stoi(value);

            if (v == v2)
            {

                if (gtn1 == '<' && gtn2 == '>')
                {
                    Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                }
                else
                {
                    // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                    Variables.setAktScope(Variables.getScope(gtn));
                }

            }
        }

        if (gtn1 == '<' && gtn2 == '>')
        {
            CPPSource.addSource("if (" + name + " == " + value + ")\n\t\tgoto "+gtnaz);
        }
        else
        {
            CPPSource.addSource("if (" + name + " == " + value + ")\n\t\t"+gtn+"();");
        }
        return;
    }
    else if (name.substr(0, 1) == "[" && value.substr(value.length() - 1, name.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ EQI ]:[ INVALID_ARGUMENT:" << name << " ] Nur das erste Argument darf eine frei waehlbare Zahl sein! " << std::endl;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (gtn1 == '<' && gtn2 == '>')
            {
                CPPSource.addSource("if (" + name + " == " + value + ")\n\t\tgoto "+gtnaz);
            }
            else
            {
                CPPSource.addSource("if (" + name + " == " + value + ")\n\t\t"+gtn+"();");
            }

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v == v2)
                {

                    if (gtn1 == '<' && gtn2 == '>')
                    {
                        Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                    }
                    else
                    {
                        // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;

                        Gotos.addLJ(Gotos.getI());
                        Gotos.setI(Gotos.getGoto(gtn).getIndex());
                        Variables.setAktScope(Variables.getScope(gtn));
                    }
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ EQI ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void not_equals_int(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);
    char gtn1 = gtn.at(0);
    char gtn2 = ' ';
    gtn2 = gtn.at(gtn.length()-1);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ EQI ]:[ GOTO_NOT_FOUND:" << gtn << "||" << gtnaz << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ NQI ]:[ VARIABLE_IS_STRING ] Die Variable(\") ist ein String!" << std::endl;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            int v = Variables.getIntegerVariable(name).getIntValue();
            int v2 = std::stoi(value);

            if (v != v2)
            {

                if (gtn1 == '<' && gtn2 == '>')
                {
                    Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                }
                else
                {
                    // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                    Variables.setAktScope(Variables.getScope(gtn));
                }
            }
        }
        if (gtn1 == '<' && gtn2 == '>')
        {
            CPPSource.addSource("if (" + name + " != " + value + ")\n\t\tgoto "+gtnaz);
        }
        else
        {
            CPPSource.addSource("if (" + name + " != " + value + ")\n\t\t"+gtn+"();");
        }
        return;
    }
    else if (name.substr(0, 1) == "[" && value.substr(value.length() - 1, name.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ NQI ]:[ INVALID_ARGUMENT:" << name << " ] Nur das erste Argument darf eine frei waehlbare Zahl sein! " << std::endl;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();
            if (gtn1 == '<' && gtn2 == '>')
            {
                CPPSource.addSource("if (" + name + " != " + value + ")\n\t\tgoto "+gtnaz);
            }
            else
            {
                CPPSource.addSource("if (" + name + " != " + value + ")\n\t\t"+gtn+"();");
            }

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v != v2)
                {

                    if (gtn1 == '<' && gtn2 == '>')
                    {
                        Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                    }
                    else
                    {
                        // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;

                        Gotos.addLJ(Gotos.getI());
                        Gotos.setI(Gotos.getGoto(gtn).getIndex());
                        Variables.setAktScope(Variables.getScope(gtn));
                    }
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ NQI ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void less_equals_int(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);
    char gtn1 = gtn.at(0);
    char gtn2 = ' ';
    gtn2 = gtn.at(gtn.length()-1);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ EQI ]:[ GOTO_NOT_FOUND:" << gtn << "||" << gtnaz << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ LQI ]:[ VARIABLE_IS_STRING ] Die Variable(\") ist ein String!" << std::endl;
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            int v = Variables.getIntegerVariable(name).getIntValue();
            int v2 = std::stoi(value);

            if (v < v2)
            {

                if (gtn1 == '<' && gtn2 == '>')
                {
                    Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                }
                else
                {
                    // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                    Variables.setAktScope(Variables.getScope(gtn));
                }
            }
        }

        if (gtn1 == '<' && gtn2 == '>')
        {
            CPPSource.addSource("if (" + name + " < " + value + ")\n\t\tgoto "+gtnaz);
        }
        else
        {
            CPPSource.addSource("if (" + name + " < " + value + ")\n\t\t"+gtn+"();");
        }
        return;
    }
    else if (name.substr(0, 1) == "[" && value.substr(value.length() - 1, name.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ LQI ]:[ INVALID_ARGUMENT:" << name << " ] Nur das erste Argument darf eine frei waehlbare Zahl sein! " << std::endl;
        exit(0);
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (gtn1 == '<' && gtn2 == '>')
            {
                CPPSource.addSource("if (" + name + " < " + value + ")\n\t\tgoto "+gtnaz);
            }
            else
            {
                CPPSource.addSource("if (" + name + " < " + value + ")\n\t\t"+gtn+"();");
            }

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v < v2)
                {
                    char gtn1 = gtn.at(0);
                    char gtn2 = ' ';
                    gtn2 = gtn.at(gtn.length()-1);

                    if (gtn1 == '<' && gtn2 == '>')
                    {
                        Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                    }
                    else
                    {
                        // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;

                        Gotos.addLJ(Gotos.getI());
                        Gotos.setI(Gotos.getGoto(gtn).getIndex());
                        Variables.setAktScope(Variables.getScope(gtn));
                    }
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ LQI ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void greater_equals_int(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);
    char gtn1 = gtn.at(0);
    char gtn2 = ' ';
    gtn2 = gtn.at(gtn.length()-1);

    if (!Gotos.findGoto(gtnaz) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ GQI ]:[ GOTO_NOT_FOUND:" << gtn << "||" << gtnaz << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;

        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ GQI ]:[ VARIABLE_IS_STRING ] Die Variable(\") ist ein String!" << std::endl;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            int v = Variables.getIntegerVariable(name).getIntValue();
            int v2 = std::stoi(value);

            if (v > v2)
            {

                if (gtn1 == '<' && gtn2 == '>')
                {
                    Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                }
                else
                {
                    // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                    Variables.setAktScope(Variables.getScope(gtn));
                }
            }
        }
        if (gtn1 == '<' && gtn2 == '>')
        {
            CPPSource.addSource("if (" + name + " > " + value + ")\n\t\tgoto "+gtnaz);
        }
        else
        {
            CPPSource.addSource("if (" + name + " > " + value + ")\n\t\t"+gtn+"();");
        }
        return;
    }
    else if (name.substr(0, 1) == "[" && value.substr(value.length() - 1, name.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ GQI ]:[ INVALID_ARGUMENT:" << name << " ] Nur das erste Argument darf eine frei waehlbare Zahl sein! " << std::endl;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();
            if (gtn1 == '<' && gtn2 == '>')
            {
                CPPSource.addSource("if (" + name + " > " + value + ")\n\t\tgoto "+gtnaz);
            }
            else
            {
                CPPSource.addSource("if (" + name + " > " + value + ")\n\t\t"+gtn+"();");
            }

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v > v2)
                {
                    char gtn1 = gtn.at(0);
                    char gtn2 = ' ';
                    gtn2 = gtn.at(gtn.length()-1);

                    if (gtn1 == '<' && gtn2 == '>')
                    {
                        Gotos.setI(Variables.getRealGoto(gtnaz).getIndex());
                    }
                    else
                    {
                        // std::cout << "EQI >> <MARKE> >> " << gtn << std::endl;

                        Gotos.addLJ(Gotos.getI());
                        Gotos.setI(Gotos.getGoto(gtn).getIndex());
                        Variables.setAktScope(Variables.getScope(gtn));
                    }
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ GQI ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}


#endif //TEST_EQUALS_HPP
