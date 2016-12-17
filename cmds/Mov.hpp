//
// Created by survari on 06.11.16.
//

#ifndef TEST_MOV_HPP
#define TEST_MOV_HPP

#include <iostream>
#include <stdlib.h>
#include "../CPPSource.hpp"

void move_string(std::vector<std::string> s)
{
    //std::cout << ">> MOS gefunden!" << std::endl;

    std::string value = s[1];
    std::string name = s[2];

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        value = value.substr(1, value.length() - 2);

        if (!Variables.isCpp())
            Variables.setStringVariable(name, value);
        CPPSource.addSource(name + " = \"" + value +"\"");
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        std::cout << "[ MAIN ]:[ MOS ]:[ VALUE_IS_INT:" << value << " ] Der Wert muss ein String sein!" << std::endl;
        return;
    }
    else
    {
        if (Variables.existsStringVariable(value))
        {
            if (!Variables.isCpp())
                Variables.setStringVariable(name, Variables.getStringVariable(value).getStringValue());
            CPPSource.addSource(name + " = " + value);
        }
        else
        {
            std::cout << "[ MAIN ]:[ MOS ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese String Variable nicht!" << std::endl;
        }
    }
}

void move_integer(std::vector<std::string> s)
{
    // std::cout << ">> MOI gefunden!" << std::endl;
    std::string value = s[1];
    std::string name = s[2];

    if (value.substr(0, 1) == "\"" && value.substr(value.length() - 1, value.length() - 2) == "\"")
    {
        std::cout << "[ MAIN ]:[ MOI ]:[ VALUE_IS_STRING:" << value << " ] Der Wert muss ein Integer sein!" << std::endl;
        exit(0);
    }
    else if (value.substr(0, 1) == "[" && value.substr(value.length() - 1, value.length() - 2) == "]")
    {
        value = value.substr(1, value.length() - 2);

        Variables.setIntegerVariable(name, std::stoi(value));
        CPPSource.addSource(name+" = "+value);
        return;
    }
    else
    {
        if (Variables.existsIntegerVariable(value))
        {
            Integer v = Variables.getIntegerVariable(value);
            int i = v.getIntValue();

            Variables.setIntegerVariable(name, i);
            CPPSource.addSource(name+" = "+value);
        }
        else
        {
            std::cout << "[ MAIN ]:[ MOI ]:[ VARIABLE_NOT_FOUND:" << value << " ] Es gibt diese Integer Variable nicht!" << std::endl;
            exit(0);
        }
    }
}

#endif //TEST_MOV_HPP
