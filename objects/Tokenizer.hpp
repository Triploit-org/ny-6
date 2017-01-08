//
// Created by survari on 06.11.16.
//

#include <iostream>
#include <vector>

#ifndef TEST_TOKENIZER_HPP
#define TEST_TOKENIZER_HPP

class Tokenizer
{
private:
    std::string code;
    std::string tmp;

    std::vector<char> splitters;
    std::vector<std::string> ecode;

    bool isStr = false;
    bool isComment;

public:
    /*Tokenizer(std::string c)
    {
        code = c;
    }*/

    std::string getCode()
    {
        return code;
    }

    void setCode(std::string c)
    {
        code = c;
    }

    std::vector<std::string> doTokenize()
    {
        tmp = "";
        splitters.clear();

        splitters.push_back(' ');
        splitters.push_back(',');
        splitters.push_back(';');

        splitters.push_back('\t');
        splitters.push_back('\n');

        for (int i = 0; i < code.length(); i++)
        {
            for (int sp = 0; sp < splitters.size(); sp++)
            {
                if (code[i] == splitters[sp] && !isStr)
                {
                    for (int sp2 = 0; sp2 < splitters.size(); sp2++)
                    {
                        while (code[i + 1] == splitters[sp2] && !isStr)
                        {
                            i++;
                        }
                    }

                    if (code[i] == ';')
                    {
                        ecode.push_back(tmp);
                        tmp = ";";
                    }

                    if (code[i] == '@')
                    {
                        ecode.push_back(tmp);
                        tmp = "@";
                    }

                    ecode.push_back(tmp);
                    tmp = "";

                    i++;
                }
            }

            tmp += code[i];
            //std::cout << tmp << std::endl;

            if (code[i] == '\"')
            {
                if (isStr)
                    isStr = false;
                else
                    isStr = true;
            }
        }

        return ecode;
    }
};

#endif //TEST_TOKENIZER_HPP
