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

    if (!Gotos.findGoto(gtn))
    {
        std::cout << "[ MAIN ]:[ EQ ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
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
                Gotos.addLJ(Gotos.getI());
                Gotos.setI(Gotos.getGoto(gtn).getIndex());
            }
        }

        CPPSource.addSource("if (" + name + " == " + value + ")\n\t\t"+gtn+"();");
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

            CPPSource.addSource("if (" + name + " == " + value + ")\n\t\t"+gtn+"();");

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v == v2)
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ EQ ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
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

    if (!Gotos.findGoto(gtn))
    {
        std::cout << "[ MAIN ]:[ EQ ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
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

            if (v != v2)
            {
                Gotos.addLJ(Gotos.getI());
                Gotos.setI(Gotos.getGoto(gtn).getIndex());
            }
        }

        CPPSource.addSource("if (" + name + " != " + value + ")\n\t\t"+gtn+"();");
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

            CPPSource.addSource("if (" + name + " != " + value + ")\n\t\t"+gtn+"();");

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v != v2)
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ EQ ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
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

    if (!Gotos.findGoto(gtn))
    {
        std::cout << "[ MAIN ]:[ EQ ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
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

            if (v < v2)
            {
                Gotos.addLJ(Gotos.getI());
                Gotos.setI(Gotos.getGoto(gtn).getIndex());
            }
        }

        CPPSource.addSource("if (" + name + " < " + value + ")\n\t\t"+gtn+"();");
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

            CPPSource.addSource("if (" + name + " < " + value + ")\n\t\t"+gtn+"();");

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v < v2)
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ EQ ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
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

    if (!Gotos.findGoto(gtn))
    {
        std::cout << "[ MAIN ]:[ EQ ]:[ GOTO_NOT_FOUND:" << gtn << " ] Es gibt diese Sprungmarke nicht!"
                  << std::endl;
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

            if (v > v2)
            {
                Gotos.addLJ(Gotos.getI());
                Gotos.setI(Gotos.getGoto(gtn).getIndex());
            }
        }

        CPPSource.addSource("if (" + name + " > " + value + ")\n\t\t"+gtn+"();");
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

            CPPSource.addSource("if (" + name + " > " + value + ")\n\t\t"+gtn+"();");

            if (!Variables.isCpp())
            {
                int v = Variables.getIntegerVariable(name).getIntValue();
                int v2 = i;

                if (v > v2)
                {
                    Gotos.addLJ(Gotos.getI());
                    Gotos.setI(Gotos.getGoto(gtn).getIndex());
                }
            }
        }
        else
        {
            std::cout << "[ MAIN ]:[ EQ ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}


#endif //TEST_EQUALS_HPP
