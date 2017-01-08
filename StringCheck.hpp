//
// Created by survari on 10.11.16.
//

#ifndef TEST_STRINGCHECK_HPP
#define TEST_STRINGCHECK_HPP

#include <cctype>
#include <iostream>
#include <vector>

class StringCheck
{
public:
    bool replaceString(std::string& string, const std::string& from, const std::string& to)
    {
        size_t start_pos = string.find(from);

        if(start_pos == std::string::npos)
            return false;

        string.replace(start_pos, from.length(), to);
        return true;
    }

    bool isNumber(const std::string& s) // Function by Charles Salvia on http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    bool containsIllegalVariableCharacter(std::string s)
    {
        std::vector<char> il;

        il.push_back('!');
        il.push_back('\"');
        il.push_back('\'');
        il.push_back('$');
        il.push_back('%');
        il.push_back('&');
        il.push_back('/');
        il.push_back('(');
        il.push_back(')');
        il.push_back('=');
        il.push_back('?');
        il.push_back('\\');
        il.push_back('}');
        il.push_back('[');
        il.push_back(']');
        il.push_back('{');
        il.push_back('.');
        il.push_back(':');
        il.push_back(',');
        il.push_back(';');
        il.push_back('<');
        il.push_back('>');
        il.push_back('|');
        il.push_back('+');
        il.push_back('*');
        il.push_back('~');
        il.push_back('#');
        il.push_back('`');
        il.push_back('^');

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < il.size(); j++)
            {
                if (s[i] == il[j])
                    return true;
            }
        }
        return false;
    }
} StringCH;

#endif //TEST_STRINGCHECK_HPP
