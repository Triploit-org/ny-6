//
// Created by survari on 10.11.16.
//

#ifndef TEST_EQUALSSTRING_HPP
#define TEST_EQUALSSTRING_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../Gotos.hpp"
#include "../Variables.hpp"
#include "../CPPSource.hpp"

void equals_equals_str(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ EQS ]:[ GOTO_NOT_FOUND:" << gtn << "||" << gtnaz << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            std::string v = Variables.getStringVariable(name).getStringValue();
            std::string v2 = value;

            if (v == v2)
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
                }
            }
        }

        CPPSource.addSource("if (" + name + " == \"" + value + "\")\n\t\t" + gtn + "();");
        return;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ EQS ]:[ VARIABLE_IS_INTEGER ] Die Variable(\") ist ein Integer!" << std::endl;
    }
    else if (name.substr(0, 1) == "\"" && value.substr(value.length() - 1, name.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ EQS ]:[ INVALID_ARGUMENT:" << name
                  << " ] Nur das erste Argument darf ein frei waehlbarer String sein! " << std::endl;
    }
    else
    {
        if (Variables.existsStringVariable(value))
        {
            String v = Variables.getStringVariable(value);
            std::string i = v.getStringValue();

            CPPSource.addSource("if (" + name + " == " + value + ")\n\t\t" + gtn + "();");

            if (!Variables.isCpp())
            {
                std::string v = Variables.getStringVariable(name).getStringValue();
                std::string v2 = i;

                if (v == v2)
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ EQS ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese String Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }

}

void not_equals_str(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ NQS ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            std::string v = Variables.getStringVariable(name).getStringValue();
            std::string v2 = value;

            if (v != v2)
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
                }
            }
        }

        CPPSource.addSource("if (" + name + " != \"" + value + "\")\n\t\t" + gtn + "();");
        return;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ NQS ]:[ VARIABLE_IS_INTEGER ] Die Variable(\") ist ein Integer!" << std::endl;
    }
    else if (name.substr(0, 1) == "\"" && value.substr(value.length() - 1, name.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ NQS ]:[ INVALID_ARGUMENT:" << name
                  << " ] Nur das erste Argument darf ein frei waehlbarer String sein! " << std::endl;
    }
    else
    {
        if (Variables.existsStringVariable(value))
        {
            String v = Variables.getStringVariable(value);
            std::string i = v.getStringValue();

            CPPSource.addSource("if (" + name + " != " + value + ")\n\t\t" + gtn + "();");

            if (!Variables.isCpp())
            {
                std::string v = Variables.getStringVariable(name).getStringValue();
                std::string v2 = i;

                if (v != v2)
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ NQS ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese String Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }

}

void less_equals_str(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ GQS ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            std::string v = Variables.getStringVariable(name).getStringValue();
            std::string v2 = value;

            if (v.length() < v2.length())
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
                }
            }
        }

        CPPSource.addSource("if (" + name + ".length() < std::string(" + value + ").length())\n\t\t" + gtn + "();");
        return;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ GQS ]:[ VARIABLE_IS_INTEGER ] Die Variable(\") ist ein Integer!" << std::endl;
    }
    else if (name.substr(0, 1) == "\"" && value.substr(value.length() - 1, name.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ GQS ]:[ INVALID_ARGUMENT:" << name
                  << " ] Nur das erste Argument darf ein frei waehlbarer String sein! " << std::endl;
    }
    else
    {
        if (Variables.existsStringVariable(value))
        {
            String v = Variables.getStringVariable(value);
            std::string i = v.getStringValue();

            CPPSource.addSource("if (" + name + ".length() < " + value + ".length())\n\t\t" + gtn + "();");

            if (!Variables.isCpp())
            {
                std::string v = Variables.getStringVariable(name).getStringValue();
                std::string v2 = i;

                if (v.length() < v2.length())
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ GQS ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese String Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }

}

void greater_equals_str(std::vector<std::string> args)
{
    std::string value = args[2];
    std::string name = args[1];
    std::string gtn = args[3];
    std::string gtnaz = gtn.substr(1, gtn.size()-2);

    if (!Gotos.findGoto(gtn) && !Variables.existsRealGoto(gtnaz))
    {
        std::cout << "[ MAIN ]:[ GQS ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
        exit(0);
    }

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
        {
            std::string v = Variables.getStringVariable(name).getStringValue();
            std::string v2 = value;

            if (v.length() > v2.length())
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
                }
            }
        }

        CPPSource.addSource("if (" + name + ".length() > std::string(" + value + ").length())\n\t\t" + gtn + "();");
        return;
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ GQS ]:[ VARIABLE_IS_INTEGER ] Die Variable(\") ist ein Integer!" << std::endl;
    }
    else if (name.substr(0, 1) == "\"" && value.substr(value.length() - 1, name.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ GQS ]:[ INVALID_ARGUMENT:" << name
                  << " ] Nur das erste Argument darf ein frei waehlbarer String sein! " << std::endl;
    }
    else
    {
        if (Variables.existsStringVariable(value))
        {
            String v = Variables.getStringVariable(value);
            std::string i = v.getStringValue();

            CPPSource.addSource("if (" + name + ".length() > " + value + ".length())\n\t\t" + gtn + "();");

            if (!Variables.isCpp())
            {
                std::string v = Variables.getStringVariable(name).getStringValue();
                std::string v2 = i;

                if (v.length() > v2.length())
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ GQS ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese String Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }

}


#endif //TEST_EQUALSSTRING_HPP
