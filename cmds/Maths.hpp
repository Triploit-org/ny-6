//
// Created by survari on 06.11.16.
//

#ifndef TEST_MATHS_HPP
#define TEST_MATHS_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "../CPPSource.hpp"
#include "../Variables.hpp"

void add_variable(std::vector<std::string> args)
{
    std::string value = args[1];
    std::string name = args[2];

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        if (Variables.existsStringVariable(name))
        {
            CPPSource.addSource(name + " = " + name + " + \"" + value + "\"");
            Variables.setStringVariable(name, Variables.getStringVariable(name).getStringValue()+value.substr(1, value.length()-2));
        }
        else
        {
            std::cout << "[ MAIN ]:[ ADD ]:[ VALUE_IS_STRING:" << value << " ] Der Wert muss ein Integer sein!"
                      << std::endl;
            exit(0);
        }
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() + std::stoi(value));
        CPPSource.addSource(name + " = " + name + " + " + value);
        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (!Variables.isCpp())
                Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() + i);
            CPPSource.addSource(name + " = " + name + " + " + value);
        }
        else if (Variables.existsStringVariable(value))
        {
            Variables.setStringVariable(name, Variables.getStringVariable(name).getStringValue()+Variables.getStringVariable(value).getStringValue());
            CPPSource.addSource(name + " = " + name + " + " + value);
        }
        else
        {
            std::cout << "[ MAIN ]:[ ADD ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void sub_variable(std::vector<std::string> args)
{
    std::string value = args[1];
    std::string name = args[2];

    // std::cout << "SUB_VARIABLE!" << std::endl;

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ SUB ]:[ VALUE_IS_STRING:" << value << " ] Der Wert muss ein Integer sein!"
                  << std::endl;
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() - std::stoi(value));
        CPPSource.addSource(name + " = " + name + " - " + value);

        //std::cout << "SUB_VARIABLE_NUMBER >> " <<  Variables.getIntegerVariable(name).getIntValue()-std::stoi(value) << " = " << Variables.getIntegerVariable(name).getIntValue() << " - " << std::stoi(value) << std::endl;

        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (!Variables.isCpp())
                Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() - i);
            CPPSource.addSource(name + " = " + name + " - " + value);

            //std::cout << "SUB_VARIABLE_VARIABLE >> " <<  Variables.getIntegerVariable(name).getIntValue()-std::stoi(value) << " = " << Variables.getIntegerVariable(name).getIntValue() << " - " << std::stoi(value) << std::endl;

        }
        else
        {
            std::cout << "[ MAIN ]:[ SUB ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void mul_variable(std::vector<std::string> args)
{

    std::string value = args[1];
    std::string name = args[2];

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ MUL ]:[ VALUE_IS_STRING:" << value << " ] Der Wert muss ein Integer sein!"
                  << std::endl;
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() + std::stoi(value));
        CPPSource.addSource(name + " = " + name + " * " + value);
        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (!Variables.isCpp())
                Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() * i);
            CPPSource.addSource(name + " = " + name + " * " + value);
        }
        else
        {
            std::cout << "[ MAIN ]:[ MUL ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void div_variable(std::vector<std::string> args)
{
    std::string value = args[1];
    std::string name = args[2];

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ DIV ]:[ VALUE_IS_STRING:" << value << " ] Der Wert muss ein Integer sein!"
                  << std::endl;
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() / std::stoi(value));
        CPPSource.addSource(name + " = " + name + " / " + value);
        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (!Variables.isCpp())
                Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() / i);
            CPPSource.addSource(name + " = " + name + " / " + value);
        }
        else
        {
            std::cout << "[ MAIN ]:[ DIV ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}

void poi_variable(std::vector<std::string> args)
{
    std::string value = args[1];
    std::string name = args[2];

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        Error.printErr("[ MAIN ]:[ POI ]:[ VALUE_IS_STRING:", value, " ] Der Wert muss ein Integer sein!");
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setIntegerVariable(name, pow(Variables.getIntegerVariable(name).getIntValue(), std::stoi(value)));
        CPPSource.addSource(name + " = pow(" + name + ", " + value+")");
        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (!Variables.isCpp())
                Variables.setIntegerVariable(name, pow(Variables.getIntegerVariable(name).getIntValue(), i));
            CPPSource.addSource(name + " = pow(" + name + ", " + value+")");
        }
        else
        {
            Error.printErr("[ MAIN ]:[ POI ]:[ VARIABLE_NOT_FOUND:", value, " ] Es gibt diese Integer Variable nicht!");
            exit(0);
        }
    }
}

void mod_variable(std::vector<std::string> args)
{
    std::string value = args[1];
    std::string name = args[2];

    // std::cout << "SUB_VARIABLE!" << std::endl;

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ MOD ]:[ VALUE_IS_STRING:" << value << " ] Der Wert muss ein Integer sein!"
                  << std::endl;
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() % std::stoi(value));
        CPPSource.addSource(name + " = " + name + " % " + value);

        //std::cout << "SUB_VARIABLE_NUMBER >> " <<  Variables.getIntegerVariable(name).getIntValue()-std::stoi(value) << " = " << Variables.getIntegerVariable(name).getIntValue() << " - " << std::stoi(value) << std::endl;

        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            if (!Variables.isCpp())
                Variables.setIntegerVariable(name, Variables.getIntegerVariable(name).getIntValue() % i);
            CPPSource.addSource(name + " = " + name + " % " + value);

            //std::cout << "SUB_VARIABLE_VARIABLE >> " <<  Variables.getIntegerVariable(name).getIntValue()-std::stoi(value) << " = " << Variables.getIntegerVariable(name).getIntValue() << " - " << std::stoi(value) << std::endl;

        }
        else
        {
            std::cout << "[ MAIN ]:[ MOD ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!"
                      << std::endl;
            exit(0);
        }
    }
}


#endif //TEST_MATHS_HPP
