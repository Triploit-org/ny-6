#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

#include "LangVars.hpp"
#include "objects/Tokenizer.hpp"
#include "objects/Parser.hpp"

#define __VERSION "4.0.4"

int main(int argc, char *args[])
{
    Scope public__aXX;
    public__aXX.setName("public__aXX");

    Variables.addScope(public__aXX);
    Variables.setAktScope(public__aXX);

    System.initCommands();
    Variables.initStrings();
    Variables.initInteger();

    Integer fos;
    fos.setIntValue(System.getOSNumber());
    fos.setName("_fos");
    fos.setWriteAble(false);
    Variables.addInteger(fos);

    std::ifstream infile;
    std::string fname;

    CPPSource.addRawSource("#include <iostream>");
    CPPSource.addRawSource("#include <cstdlib>");
    CPPSource.addRawSource("#include <cstdio>\n");
    CPPSource.addRawSource("#include <cmath>\n");
    CPPSource.addRawSource("");

    CPPSource.addRawSource("#ifdef _WIN32");
    CPPSource.addRawSource("int _fos = 0;");
    CPPSource.addRawSource("#elif _WIN64");
    CPPSource.addRawSource("int _fos = 1;");
    CPPSource.addRawSource("#elif __unix || __unix__");
    CPPSource.addRawSource("int _fos = 2;");
    CPPSource.addRawSource("#elif __APPLE__ || __MACH__");
    CPPSource.addRawSource("int _fos = 3;");
    CPPSource.addRawSource("#elif __linux__");
    CPPSource.addRawSource("int _fos = 4;");
    CPPSource.addRawSource("#elif __FreeBSD__");
    CPPSource.addRawSource("int _fos = 5;");
    CPPSource.addRawSource("#else");
    CPPSource.addRawSource("int _fos = 6;");
    CPPSource.addRawSource("#endif");
    CPPSource.addRawSource("");

    CPPSource.addRawSource("std::string _SN = \"\";");
    CPPSource.addRawSource("int _IN = 0;");
    CPPSource.addRawSource("");

    CPPSource.addRawSource("int _axi = 0;");
    CPPSource.addRawSource("int _cxi = 0;");
    CPPSource.addRawSource("int _dxi = 0;");
    CPPSource.addRawSource("int _exi = 0;");
    CPPSource.addRawSource("");

    CPPSource.addRawSource("std::string _axs = \"\";");
    CPPSource.addRawSource("std::string _cxs = \"\";");
    CPPSource.addRawSource("std::string _dxs = \"\";");
    CPPSource.addRawSource("std::string _exs = \"\";");
    CPPSource.addRawSource("std::string _NL = \"\\n\";");
    CPPSource.addRawSource("");

    /*
     * TODO ============================== BEGIN
     *
     *  TODO >> INCLUDE FUNCTION               | / | >>  Tokenizer
     *
     * TODO ================================= END
     */

    if (argc == 2)
    {
        Variables.setCpp(true);
        CPPSource.setCpp(true);

        if (strcmp(args[1], "-v") == 0 || strcmp(args[1], "--version") == 0)
        {
            std::cout << "Version " << __VERSION << std::endl << std::endl;
            std::cout << "Ny++6 - Compiler\nInterpreter deaktiviert.\nNur Uebersetzung in C++ moeglich." << std::endl;
            exit(0);
        }
        else
        {
            fname = args[1];
            fname = fname.substr(fname.length() - 2, fname.length());

            if (fname == "n6")
            {
                infile = std::ifstream(args[1]);
            }
            else
            {
                std::cout << "[ MAIN ] Falsche Dateiendung(" << fname << ")! Erwartet: *.n6" << std::endl;
                exit(0);
            }
        }
    }
    else if (argc == 0 || argc < 2)
    {
        std::cout << "[ MAIN ] Bitte gib eine Datei an!" << std::endl;
        exit(0);
    }
    else if (argc == 3)
    {
        if (strcmp(args[1], "-cc") == 0)
        {
            Variables.setCpp(true);
            CPPSource.setCpp(true);
            // std::cout << Variables.isCpp() << std::endl;
        }

        fname = args[2];
        fname = fname.substr(fname.length() - 2, fname.length());

        if (fname == "n6")
        {
            infile = std::ifstream(args[2]);
        }
        else
        {
            std::cout << "[ MAIN ] Falsche Dateiendung(" << fname << ")! Erwartet: *.n6" << std::endl;
            exit(0);
        }
    }

    std::string code = "";
    std::string line;

    if (infile)
    {
        while (std::getline(infile, line))
        {
            if (line.substr(0, 4) == "%inc")
            {
                // std::cout << "INC!" << std::endl;

                line = line.substr(5, line.size());
                std::ifstream f = std::ifstream(line);

                while (std::getline(f, line))
                {
                    if (line.substr(0, 4) == "%def")
                    {
                        line = line.substr(5, line.size());

                        PVariable p;
                        p.setName(line);
                        PraeVars.addPVar(p);
                    }
                    else if (line.substr(0, 4) == "%undef")
                    {
                        line = line.substr(7, line.size());

                        PVariable p;
                        p.setName(line);
                        PraeVars.removePVar(p.getName());
                    }
                    else
                    {
                        code = code + line + " [NL:97:LN] ";
                    }
                }
            }
            else if (line.substr(0, 6) == "%indic")
            {
                // std::cout << "INDIC!" << std::endl;

                line = line.substr(7, line.size());
                std::string file = "";
                std::string var = "";

                int ind = 0;

                for (int i = 0; line[i] != ' '; i++)
                {
                    var += line[i];
                    ind = i + 1;
                }
                ind++;

                // std::cout << "WEITER" << std::endl;
                // std::cout << ind << " < " << line.size() << std::endl;

                for (int i = ind; line[i] != ' ' && i < line.size(); i++)
                {
                    file += line[i];
                    // std::cout << "FILE=" << file << std::endl;
                }

                // %indic var test.n6 -> var test.txt

                if (!PraeVars.existsVar(var))
                {
                    std::ifstream f = std::ifstream(file);

                    while (std::getline(f, line))
                    {
                        if (line.substr(0, 4) == "%def")
                        {
                            line = line.substr(5, line.size());

                            PVariable p;
                            p.setName(line);
                            PraeVars.addPVar(p);
                            // std::cout << "def " << p.getName() << std::endl;
                        }
                        else if (line.substr(0, 6) == "%undef")
                        {
                            line = line.substr(7, line.size());

                            PVariable p;
                            p.setName(line);
                            PraeVars.removePVar(p.getName());
                        }
                        else
                        {
                            //std::cout << var << " " << file << "] " << line << std::endl;
                            code = code + line + " [NL:97:LN] ";
                        }
                    }

                }
            }
            else if (line.substr(0, 4) == "%def")
            {
                // std::cout << "DEF!" << std::endl;
                line = line.substr(5, line.size());

                PVariable p;
                p.setName(line);
                PraeVars.addPVar(p);
            }
            else if (line.substr(0, 4) == "%undef")
            {
                // std::cout << "UNDEF!" << std::endl;
                line = line.substr(7, line.size());

                PVariable p;
                p.setName(line);
                PraeVars.removePVar(p.getName());
            }
            else
            {
                code = code + line + " [NL:97:LN] ";
                line = "";
            }
        }

        // %tX => Tab
        // %nX => NewLine
        // %aX => "

        if (CPPSource.isCpp())
        {
            for (int x = 0; x < code.size(); x++)
            {
                StringCH.replaceString(code, "%tX", "\\t");
                StringCH.replaceString(code, "%nX", "\\n");
                StringCH.replaceString(code, "%aX", "\\\"");
            }

            for (int x = 0; x < code.size(); x++)
            {
                StringCH.replaceString(code, "%ttX", "%tX");
                StringCH.replaceString(code, "%nnX", "%nX");
                StringCH.replaceString(code, "%aaX", "%aX");
            }
        }

        Tokenizer t;
        t.setCode(code);

        Parser p;
        p.setCode(t.doTokenize());
        p.parseAll();

    }
    else
    {
        std::cout << "[ MAIN ] Konnte die Datei " << args[1] << " nicht oeffnen!" << std::endl;
        return 1;
    }

    if (Variables.isCpp())
    {
        std::cout << std::endl << std::endl << CPPSource.getSource() << std::endl;
        std::string n;
        std::string n2;

        if (argc == 3)
            n2 = args[2];
        else if (argc == 2)
            n2 = args[1];

        std::string cmd;
        std::string ans;

        n2 = n2.substr(0, n2.length() - 3);
        n2 += ".cpp";

        std::fstream f;
        f.open(n2, std::ios::out);

        f << CPPSource.getSource() << std::endl;
        f.close();

        if (argc == 3)
            n = args[2];
        else if (argc == 2)
            n = args[1];

        n = n.substr(0, n.length() - 3);
        cmd = "g++ -o " + n + " " + n2;

        while (ans != "y" && ans != "yes" && ans != "Yes" && ans != "YEs" && ans != "YES" && ans != "yEs" &&
               ans != "yES" && ans != "YeS")
        {
            std::cout << "Moechtest du die Datei kompilieren (G++ erforderlich)? y/n :: ";
            std::cin >> ans;

            if (ans == "n" || ans == "No" || ans == "NO" || ans == "nO" || ans == "no")
            {
                std::cout << "Nicht kompiliert >> ENDE" << std::endl;
                return 0;
            }
        }

        std::cout << "Kompilieren... " << std::endl;
        std::cout << "[ SYSTEM ] g++ -o " << n << " " << n2 << std::endl;

        std::cout << "[ BEG_ ]" << std::endl;
        system(cmd.c_str());
        std::cout << "[ END_ ]" << std::endl;
    }
    return 0;
}
