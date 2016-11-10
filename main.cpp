#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

#include "LangVars.hpp"
#include "Tokenizer.hpp"
#include "Parser.hpp"

int main(int argc, char *args[])
{
    std::ifstream infile;
    std::string fname;
    CPPSource.addRawSource("#include <iostream>");

    CPPSource.addRawSource("#include <cstdlib>");
    CPPSource.addRawSource("#include <cstdio>\n");

    CPPSource.addRawSource("std::string _SN = \"\";");
    CPPSource.addRawSource("int _IN = 0;");

    /*
     * TODO ============================== BEGIN
     *
     *  TODO >> NQI   COMMAND                  |   | >>  Equals
     *  TODO >> EQI   COMMAND                  | X | >>  Equals
     *  TODO >> GQI   COMMAND                  |   | >>  Equals
     *  TODO >> LQI   COMMAND                  |   | >>  Equals
     *
     *  TODO >> NQS   COMMAND                  |   | >>  Equals
     *  TODO >> EQS   COMMAND                  |   | >>  Equals
     *  TODO >> GQS   COMMAND                  |   | >>  Equals
     *  TODO >> LQS   COMMAND                  |   | >>  Equals
     *
     *  TODO >> SLEEP COMMAND                  |   | >>  Maths
     *  TODO >> GCA   COMMAND                  |   | >>  StringOps
     *  TODO >> STI   COMMAND                  |   | >>  StringOps
     *
     *  TODO >> INCLUDE FUNCTION               |   | >>  Tokenizer
     *
     * TODO ================================= END
     */

    if (argc == 2)
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
    else if (argc == 3)
    {
        if (strcmp(args[1], "-cc") == 0)
        {
            Variables.setCpp(true);
            std::cout << Variables.isCpp() << std::endl;
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

    System.initCommands();
    Variables.initStrings();
    Variables.initInteger();

    if (infile)
    {
        while (std::getline(infile, line))
        {

            code = code + line + " [NL:97:LN] ";
            line = "";
        }


        Tokenizer t;
        t.setCode(code);

        Parser p;
        p.setCode(t.doTokenize());
        p.parseAll();

    }
    else
    {
        std::cout << "[ MAIN ] Konnte die Datei " << args[1] << " nicht öffnen!" << std::endl;
        return 1;
    }

    if (Variables.isCpp())
    {
        std::cout << CPPSource.getSource() << std::endl;
        std::string n;
        std::string n2;
        n2 = args[2];
        std::string cmd;
        std::string ans;

        n2 = n2.substr(0, n2.length() - 3);
        n2 += ".cpp";

        std::fstream f;
        f.open(n2, std::ios::out);

        f << CPPSource.getSource() << std::endl;
        f.close();

        n = args[2];
        n = n.substr(0, n.length() - 3);
        cmd = "g++ -o " + n + " " + n2;

        while (ans != "y" && ans != "yes" && ans != "Yes" && ans != "YEs" && ans != "YES" && ans != "yEs" &&
               ans != "yES" && ans != "YeS")
        {
            std::cout << "Moechtest du die Datei kompilieren (G++ erforderlich)? y/n :: ";
            std::cin >> ans;

            if (ans == "n" || ans == "No" || ans == "NO" || ans == "nO" || ans == "no")
            {
                std::cout << "Nicht kompiliert. >> ENDE" << std::endl;
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