//
// Created by survari on 06.11.16.
//

#ifndef TEST_PARSER_HPP
#define TEST_PARSER_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../LangVars.hpp"
#include "../CPPSource.hpp"
#include "Goto.hpp"
#include "../Gotos.hpp"
#include "../StringCheck.hpp"
#include <sstream>

class Parser
{
private:
    std::vector<std::string> args;
    std::vector<Command> cmds = System.getCommands();
    int i = Gotos.getI();
    std::string aktgoto = "public__aXX";
    std::vector<std::string> code;

public:
    void setCode(std::vector<std::string> c)
    {
        code = c;
    }


    void parseAll()
    {
        bool isfm = true;
        if (CPPSource.isCpp()) std::cout << "Starte Praeprozessor." << std::endl;

        // Praeprozessor
        for (i = Gotos.getI(); i < code.size(); i++)
        {
            if (code[i].substr(0, 1) == "{" && code[i].substr(code[i].length() - 1, code[i].length() - 2) == "}")
            {
                std::string marke = code[i].substr(1, code[i].length() - 2);

                if (Gotos.findGoto(marke))
                {
                    std::cout << "[ MAIN ]:[ PRAE ]:[ ALREADY_EXISTS:" << marke << " ] Sprungmarke existiert schon!" << std::endl;
                    exit(0);
                }

                if (StringCH.isNumber(marke))
                {
                    std::cout << "[ MAIN ]:[ PRAE ]:[ INVALID_GOTO_LABEL:" << marke
                              << " ] Die Sprungmarke besteht nur aus Zahlen!"
                              << std::endl;
                    exit(0);
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

                Goto g;
                g.setName(marke);

                g.setIndex(i);
                Gotos.addGoto(g);

                // std::cout << "Sprungmarke(PRAE):\t" << code[i] << " -> " << marke << " || " << i << std::endl;
                aktgoto = marke;

                Scope n;
                n.setName(marke);

                Variables.addScope(n);
                Variables.setAktScope(Variables.getScope(n.getName()));
                CPPSource.addRawSource("int " + marke + "();");
            }
            else
            {
                std::string gtn = code[i].substr(1, code[i].size()-3);

                char gtn1 = code[i].at(0);
                char gtn2 = ' ';

                if (code[i].size() > 1)
                    gtn2 = code[i].at(code[i].length()-2);

                if (gtn1 == '(' && gtn2 == ')')
                {
                    if (!Variables.existsRealGoto(gtn))
                    {
                        RealGoto rg(gtn, i);
                        Variables.addRealGoto(rg);
                    }
                    else
                    {
                        Error.printErr("[ MAIN ]:[ PRAE ]:[ RGOTO ]:[ ALREADYEXISTS:",gtn," ] Goto (!=func) existiert schon!");
                    }
                }
                else if (code[i] == "endf")
                {
                    Gotos.setGotoClosed(aktgoto, true);
                }
            }
        }

        if (CPPSource.isCpp()) std::cout << "Verlasse Praeprozessor." << std::endl;
        CPPSource.addRawSource("");
        aktgoto = "public__aXX";
        Variables.setAktScope(Variables.getScope(aktgoto));

        Gotos.setI(0);
        bool gmain;

        if (Gotos.findGoto("main"))
        {
            gmain = true;
        }
        else
        {
            std::cout << "[ MAIN ]:[ COMPILER ]:[ CPP ]:[ MAIN_NOT_FOUND ] Es muss eine Main-Funktion geben!"
                      << std::endl;
            exit(0);
        }

        if (CPPSource.isCpp()) std::cout << "Starte Parser." << std::endl;
        // Command Parser & Executor
        int i2 = 0;
        for (i = Gotos.getI(); i < code.size() && i2 < code.size(); i = Gotos.getI())
        {
            if (CPPSource.isCpp())
            {
                i = i2;
            }

            std::string gtn = code[i].substr(1, code[i].size()-3);

            char gtn1 = code[i].at(0);
            char gtn2 = ' ';

            if (code[i].size() > 1)
                gtn2 = code[i].at(code[i].length()-2);

            if (code[i].substr(0, 1) == "{" && code[i].substr(code[i].length() - 1, code[i].length() - 2) == "}")
            {
                if (gmain && !Variables.isCpp())
                {
                    i = Gotos.getGoto("main").getIndex();
                    Gotos.setI(i);
                    gmain = false;

                    Scope n;
                    n.setName("main");
                    Variables.addScope(n);
                    Variables.setAktScope(Variables.getScope(n.getName()));
                }

                std::string marke = code[i].substr(1, code[i].length() - 2);
                //std::cout << "Funktion: " << marke << std::endl;

                if (!Gotos.getGoto(marke).isAlreadyDefined())
                {
                    CPPSource.addRawSource("\nint " + marke + "()\n{");
                    Gotos.getGoto(marke).setAlreadyDefined(true);

                    Scope n;
                    n.setName(marke);
                    Variables.addScope(n);
                    Variables.setAktScope(Variables.getScope(n.getName()));

                    aktgoto = marke;
                    //std::cout << "AKTGT = " << marke << std::endl;
                }

            }

            if (gtn1 == '(' && gtn2 == ')')
            {
                CPPSource.addRawSource(gtn+":");
                //std::cout << "ADD RGOTO S:" << Variables.getAktScope().getRealGotos().size() << " >> \"" << gtn << "\" AT " << i << std::endl;
                //std::cout << CPPSource.getSource() << std::endl;
                //exit(0);
            }


            char ab = 13;
            char ac = 64;
            char arr[2] = {ab, ac};
            std::string at(arr);

            if (code[i].find('@') == 0 && code[i].find('"') != 0) // DAS IST SCHWERSTE AUFGABE IM PARSER GEWESEN...
            {
                if (!Variables.isCpp())
                    std::cout << std::endl;
                CPPSource.addSource("std::cout << std::endl");

                i++;
                Gotos.setI(i);

            }

            for (int j = 0; j < cmds.size(); j++)
            {
                if (code[i] ==
                    cmds[j].getName()) //&& aktgoto != "public__aXX" && (code[i] != "defi" || code[i] != "defs"))
                {
                    for (int ar = 0; ar <= cmds[j].getArgCount(); ar++)
                    {
                        args.push_back(code[i]);

                        i++;
                        Gotos.setI(i);
                    }

                    cmds[j].runFunction(args);
                    args.clear();

                }

                if (code[i] == "[NL:97:LN]")
                {
                    System.addLineCount();
                    Gotos.addLineCount();
                    Variables.addLineCount();
                }
                else
                {
                    if (code[i] == "cl" && aktgoto != "public_aXX")
                    {
                        std::string gt = code[i + 1];

                        if (Gotos.getGoto(gt).getIndex() == -999)
                        {
                            std::cout << "[ MAIN ]:[ GOTO ] Die Sprungmarke " << gt << " existiert nicht!" << std::endl;
                            exit(0);
                        }
                        else
                        {
                            Gotos.addLJ(i+1);
                            Gotos.addLS(Variables.getAktScope().getName());

                            if (!Variables.isCpp())
                            {
                                i = Gotos.getGoto(gt).getIndex();
                                Gotos.setI(Gotos.getGoto(gt).getIndex());
                            }

                            CPPSource.addSource(gt + "()");
                            CPPSource.addRawSource("");

                            if (!CPPSource.isCpp())
                                Variables.setAktScope(Variables.getScope(gt));
                            //Variables.listScopes();

                            // std::cout << ">>  " << Variables.getScope("main").getIntegers().size() << std::endl;
                            // std::cout << "BEGINNE :: " << gt << std::endl;

                            // aktgoto = gt;
                            break;
                        }
                    }
                    else if (code[i] == "gt" && aktgoto != "public_aXX")
                    {
                        std::string gt = code[i + 1];

                        if (Variables.getAktScope().existsRealGoto(gt))
                        {
                            if (!Variables.isCpp())
                            {
                                Gotos.setI(Variables.getRealGoto(gt).getIndex());
                                i = Gotos.getI();
                            }

                            CPPSource.addSource("goto "+gt);
                            break;
                        }
                        else
                        {
                            Error.printErr("[ MAIN ]:[ PARSER ]:[ GOTO ]:[ GT ]:[ NOTFOUND:", gt, " IN:",Variables.getAktScope().getName()," ] Sprungmarke (!=func) nicht gefunden!");
                            //std::cout << "S: ]] " << Variables.getRealGoto("begOk2").getIndex() << std::endl;
                            exit(0);
                        }
                    }
                    else if (code[i] == "return" && aktgoto != "public_aXX")
                    {
                        Variables.clearVariables();

                        if (!Variables.isCpp())
                        {
                            Gotos.setI(Gotos.getLJ());
                            i = Gotos.getI();
                            Variables.setAktScope(Variables.getScope(Gotos.getLS()));
                        }

                        CPPSource.addSource("return 0");
                        break;
                    }
                    else if (code[i] == "end" && aktgoto != "public_aXX")
                    {
                        if (!Variables.isCpp())
                            exit(0);
                        CPPSource.addSource("exit(0)");
                        break;
                    }
                    else if (code[i] == "endf")
                    {
                        CPPSource.addRawSource("}");
                        Variables.clearVariables();

                        if (!Variables.isCpp())
                        {
                            if (aktgoto == "main")
                            {
                                //std::cout << "XXX" << std::endl;
                                exit(0);
                            }
                            else
                            {
                                Gotos.setI(Gotos.getLJ());
                                Variables.setAktScope(Variables.getScope(Gotos.getLS()));
                            }
                        }
                        break;
                    }
                }
            }

            if (!Variables.isCpp()) Gotos.setI((Gotos.getI() + 1));
            i2++;
            //std::cout << Gotos.getI() << std::endl;
        }

        //CPPSource.addRawSource("\n\treturn 0;\n}");
        if (CPPSource.isCpp()) std::cout << "Beende Parser" << std::endl;
    }
};

#endif //TEST_PARSER_HPP
