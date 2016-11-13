//
// Created by survari on 06.11.16.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "LangVars.hpp"
#include "CPPSource.hpp"
#include "Goto.hpp"
#include "Gotos.hpp"
#include "StringCheck.hpp"

#ifndef TEST_PARSER_HPP
#define TEST_PARSER_HPP

class Parser
{
private:
    std::vector<std::string> args;
    std::vector<Command> cmds = System.getCommands();
    int i = Gotos.getI();
    std::string aktgoto;
    std::vector<std::string> code;

public:
    void setCode(std::vector<std::string> c)
    {
        code = c;
    }

    void parseAll()
    {
        bool isfm = true;
        CPPSource.addRawSource("int main()\n{");

        for (i = Gotos.getI(); i < code.size(); i = Gotos.getI())
        {
            if (code[i].substr(0, 1) == "{" && code[i].substr(code[i].length() - 1, code[i].length() - 2) == "}")
            {
                std::string marke = code[i].substr(1, code[i].length() - 2);

                /*
                if (StringCH.isNumber(marke))
                {
                    std::cout << "[ MAIN ]:[ PRAE ]:[ INVALID_GOTO_LABEL:" << marke
                              << " ] Die Sprungmarke besteht nur aus Zahlen!"
                              << std::endl;
                }

                if (Gotos.getGoto(aktgoto).getIndex() != -999)
                {
                    if (!Gotos.getGoto(aktgoto).isClosed())
                    {
                        std::cout << "[ MAIN ]:[ PRAE ]:[ NOT_CLOSED:" << aktgoto
                                  << " ] Dieser Sprungmarkenbereich wurde nicht geschlossen!" << std::endl;
                        exit(0);
                    }
                }

                if (isfm && marke != "main")
                {
                    std::cout << "[ MAIN ]:[ PRAE ]:[ FIRST_IS_NOT_MAIN:" << marke
                              << " ] Die erste Sprungmarke die deklariert wird muss \"main\" heißen!" << std::endl;
                    exit(0);
                }
                else if (isfm && marke == "main")
                {
                    isfm = false;
                }
                */

                Goto g;
                g.setName(marke);

                g.setIndex(i);
                Gotos.addGoto(g);

                // std::cout << "Sprungmarke(PRAE):\t" << code[i] << " -> " << marke << " || " << i << std::endl;
                aktgoto = marke;
            }
            else
            {

                if (code[i] == "endf")
                {
                    std::cout << Gotos.getGoto(aktgoto).isClosed() << std::endl;
                }
            }

            // std::cout << "MAIN: " << i << " == " << Gotos.getI() << std::endl;
            Gotos.setI((Gotos.getI() + 1));
        }

        if (Gotos.getGoto(aktgoto).getIndex() != -999)
        {
        }

        CPPSource.addRawSource("");
        aktgoto = "";

        Gotos.setI(0);
        // else
        // {
        //     std::cout << "[ MAIN ]:[ COMPILER ]:[ C++ ]:[ MAIN_NOT_FOUND ] Es muss eine Main-Funktion geben!"
        //               << std::endl;
        //     exit(0);
        // }

        for (i = Gotos.getI(); i < code.size(); i = Gotos.getI())
        {
            if (code[i].substr(0, 1) == "{" && code[i].substr(code[i].length() - 1, code[i].length() - 2) == "}")
            {
                std::string marke = code[i].substr(1, code[i].length() - 2);
                //std::cout << "Sprungmarke:\t\t" << code[i] << " -> " << marke << " || " << i << std::endl;

                if (!Gotos.getGoto(marke).isAlreadyDefined())
                {
                    CPPSource.addRawSource(marke+":");
                    Gotos.getGoto(marke).setAlreadyDefined(true);

                    aktgoto = marke;
                }

                i++;
                Gotos.setI(i);
            }

            else if (code[i] == "@")
            {
                if (!Variables.isCpp())
                    std::cout << std::endl;
                CPPSource.addSource("std::cout << std::endl");

                i++;
                Gotos.setI(i);
            }

            for (int j = 0; j < cmds.size(); j++)
            {
                if (code[i] == cmds[j].getName())
                {
                    for (int ar = 0; ar <= cmds[j].getArgCount(); ar++)
                    {
                        args.push_back(code[i]);

                        i++;
                        Gotos.setI(i);
                    }

                    cmds[j].runFunction(args);
                    args.clear();

                    if (code[i] != ";" && code[i] != "[NL:97:LN]" && code[i] != "")
                    {
                        std::string err = "[ MAIN ]:[ PARSER ]:[ MISSING_SEMICOLON ] Fehlendes Semikolon/Schlusszeichen! ";
                        err += "\n";
                        System.printError(err);
                    }
                }

                if (code[i] == "[NL:97:LN]")
                {
                    System.addLineCount();
                }
                else
                {
                    if (code[i] == "gt")
                    {
                        std::string gt = code[i + 1];
                        Gotos.setLJ(i);

                        if (Gotos.getGoto(gt).getIndex() == -999)
                        {
                            std::cout << "[ MAIN ]:[ GOTO ] Die Sprungmarke " << gt << " existiert nicht!" << std::endl;
                            exit(0);
                        }
                        else
                        {
                            if (!Variables.isCpp())
                            {
                                i = Gotos.getGoto(gt).getIndex();
                                Gotos.setI(Gotos.getGoto(gt).getIndex());
                            }



                            CPPSource.addSource(gt + "()");
                            CPPSource.addRawSource("");
                            //std::cout << "BEGINNE :: " << gt << std::endl;
                            //aktgoto = gt;
                            break;
                        }
                    }
                    else if (code[i] == "end")
                    {
                        if (!Variables.isCpp())
                            exit(0);
                        CPPSource.addSource("exit(0)");
                        break;
                    }
                }
            }

            Gotos.setI((Gotos.getI() + 1));
            //std::cout << Gotos.getI() << std::endl;
        }

        CPPSource.addRawSource("\n\treturn 0;\n}");
    }
};

#endif //TEST_PARSER_HPP
