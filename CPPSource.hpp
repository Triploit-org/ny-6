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
    bool iscpp = false;
public:
    bool isCpp()
    {
        return iscpp;
    }

    void setCpp(bool b)
    {
        iscpp = b;
    }

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
} CPPSource;

#endif //TEST_CPPSOURCE_HPP
