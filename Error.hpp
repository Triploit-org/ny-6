//
// Created by survari on 20.11.16.
//

#ifndef TEST_ERROR_HPP
#define TEST_ERROR_HPP

#include <iostream>
#include "Gotos.hpp"

class Error
{
public:
    void printErr(std::string s, std::string s1="", std::string s2="", std::string s3="", std::string s4="")
    {
        s = s+s1+s2+s3+s4;
        std::cout << "[ L:" << Gotos.getLine() << "/" << Gotos.getLine()+1 << " ] " << s << std::endl;
    }
} Error;


#endif //TEST_ERROR_HPP
