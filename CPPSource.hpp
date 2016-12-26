//
// Created by survari on 06.11.16.
//

#ifndef TEST_CPPSOURCE_HPP
#define TEST_CPPSOURCE_HPP

#include <iostream>

class CPPSource
{
private:
    std::string source = "";
public:
    void addSource(std::string s)
    {
        source = source + "\t" + s + ";\n";
    }

    void addRawSource(std::string s)
    {
        source = source + s + "\n";
    }

    std::string getSource()
    {
        return source;
    }

    void setSource(std::string src)
    {
        source = src;
    }
} CPPSource;

#endif //TEST_CPPSOURCE_HPP
