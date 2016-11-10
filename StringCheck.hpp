//
// Created by survari on 10.11.16.
//

#ifndef TEST_STRINGCHECK_HPP
#define TEST_STRINGCHECK_HPP

#include <cctype>
#include <iostream>

class StringCheck
{
public:
    bool isNumber(const std::string& s) // Function by Charles Salvia on http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
} StringCH;

#endif //TEST_STRINGCHECK_HPP
