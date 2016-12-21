//
// Created by root on 12/19/16.
//

#ifndef TEST_FILESYSTEM_H
#define TEST_FILESYSTEM_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "../Error.hpp"
#include "../Variables.hpp"
#include "../CPPSource.hpp"
#include <unistd.h>
#include <fstream>
#include <sys/stat.h>

void create_new_file(std::vector<std::string> args)
{
    std::string name = args[1];
    char start = name.at(0);
    char end = name.at(name.size()-1);

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CNF ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            name = name.substr(1, name.size()-2);
            std::fstream f;
            f.open(name, std::ios::out);

            f << "[CBN6]:[FS]:[NOERR]" << std::endl;
            f.close();
            // std::cout << "1 Datei " << name << " erstellt!" << std::endl;
        }

        CPPSource.addSource("f.open("+name+", std::ios::out)");
        CPPSource.addSource("f << \"[CBN6]:[FS]:[NOERR]\" << std::endl");
        CPPSource.addSource("f.close()");
        return;
    }

    else if (Variables.existsIntegerVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CNF ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CNF ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp())
        {
            std::fstream f;
            f.open(Variables.getStringVariable(name).getStringValue(), std::ios::out);

            f << "[CBN6]:[FS]:[NOERR]" << std::endl;
            f.close();
            // std::cout << "2 Datei " << name << " erstellt!" << std::endl;
        }

        CPPSource.addSource("f.open("+name+", std::ios::out)");
        CPPSource.addSource("f << \"[CBN6]:[FS]:[NOERR]\" << std::endl");
        CPPSource.addSource("f.close()");
        return;
    }
}

void delete_file(std::vector<std::string> args)
{
    // CNF
    std::string name = args[1];
    char start = name.at(0);
    char end = name.at(name.size()-1);

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ DF ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            name = name.substr(1, name.size()-2);
            remove(name.c_str());
        }

        CPPSource.addSource("remove("+name+");");
        return;
    }

    else if (Variables.existsIntegerVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ DF ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ DF ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp())
            remove(Variables.getStringVariable(name).getStringValue().c_str());

        CPPSource.addSource("remove("+name+".c_str());");
        return;
    }
}

void create_new_directory(std::vector<std::string> args)
{
    // CND : CNF
    std::string name = args[1];
    char start = name.at(0);
    char end = name.at(name.size()-1);

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CND ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            name = name.substr(1, name.size() - 2);
            #ifdef _WIN32 || _WIN64
                mkdir(name.c_str());
            #else
                mkdir(name.c_str(), 755);
            #endif
        }


    #ifdef _WIN32 || _WIN64
        CPPSource.addSource("mkdir("+name+")");
    #else
        CPPSource.addSource("mkdir("+name+", 755)");
    #endif
        return;
    }

    else if (Variables.existsIntegerVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CND ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CND ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp())
        {
            #ifdef _WIN32 || _WIN64
                mkdir(Variables.getStringVariable(name).getStringValue().c_str());
            #else
                mkdir(Variables.getStringVariable(name).getStringValue().c_str(), 755);
            #endif
        }

        #ifdef _WIN32 || _WIN64
            CPPSource.addSource("mkdir("+name+".c_str())");
        #else
            CPPSource.addSource("mkdir("+name+".c_str(), 755)");
        #endif

        return;
    }
}

void delete_directory(std::vector<std::string> args)
{
    // DD : CNF

    std::string name = args[1];
    char start = name.at(0);
    char end = name.at(name.size()-1);

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ DD ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            name = name.substr(1, name.size() - 2);
            rmdir(name.c_str());
        }

        CPPSource.addSource("rmdir("+name+");");
        return;
    }

    else if (Variables.existsIntegerVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ DD ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ DD ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp())
            rmdir(Variables.getStringVariable(name).getStringValue().c_str());

        CPPSource.addSource("rmdir("+name+".c_str());");
        return;
    }
}

void change_directory(std::vector<std::string> args)
{
    // CD : CNF
    std::string name = args[1];
    char start = name.at(0);
    char end = name.at(name.size()-1);

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CD ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            name = name.substr(1, name.size()-2);
            chdir(name.c_str());
        }

        CPPSource.addSource("chdir("+name+");");
        return;
    }

    else if (Variables.existsIntegerVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CD ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(name))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ CD ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp())
            chdir(Variables.getStringVariable(name).getStringValue().c_str());

        CPPSource.addSource("chdir("+name+".c_str());");
        return;
    }
}

void read_all_text_from_file(std::vector<std::string> args)
{
    std::string variable = args[1];
    std::string name = args[2];

    char start = variable.at(0);
    char end = variable.at(variable.size()-1);

    char nstart = name.at(0);
    char nend = name.at(name.size()-1);

    if (nstart == '"' && nend == '"')
    {
        if (!Variables.isCpp()) name = name.substr(1, name.size());
    }
    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp()) name = Variables.getStringVariable(name).getStringValue();
    }
    else
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ RTF ]:[ NOTFOUND:",name," ] String-Variable nicht gefunden!");
    }

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ RTF ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            std::string line = name;
            std::string filename = line.substr(1, line.size()-2);
            std::ifstream f = std::ifstream(filename);

            while (std::getline(f, line))
            {
                std::cout << line << std::endl;
            }

            f.close();
        }

        std::string d = "";
        CPPSource.addSource("\n\tstd::string line = "+name+"");
        CPPSource.addSource("std::string filename"+std::to_string(Gotos.getI())+" = line.substr(1, line.size()-2)");
        CPPSource.addSource("std::ifstream f"+std::to_string(Gotos.getI()) + " = std::ifstream(filename"+std::to_string(Gotos.getI())+")");
        CPPSource.addRawSource("\n\twhile (std::getline(f"+std::to_string(Gotos.getI())+", line))");
        CPPSource.addRawSource("\t{\n");
        CPPSource.addSource("\tstd::cout << line << std::endl");
        CPPSource.addRawSource("\t}\n");
        CPPSource.addSource("f"+std::to_string(Gotos.getI())+".close()");
        return;
    }

    else if (Variables.existsIntegerVariable(variable))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ RTF ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(variable))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ RTF ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(variable))
    {
        if (!Variables.isCpp())
        {
            std::string c = "";
            std::string line = name;

            std::string filename = line;
            std::ifstream f = std::ifstream(filename);

            while (std::getline(f, line))
            {
                c = c + line;
            }

            f.close();
            Variables.setStringVariable(variable, c);
        }
        CPPSource.addSource("\n\tstd::string line = "+name+"");
        CPPSource.addSource("std::string filename"+std::to_string(Gotos.getI())+" = line");
        CPPSource.addSource("std::ifstream f"+std::to_string(Gotos.getI()) + " = std::ifstream(filename"+std::to_string(Gotos.getI())+")");
        CPPSource.addRawSource("\n\twhile (std::getline(f"+std::to_string(Gotos.getI())+", line))");
        CPPSource.addRawSource("\t{\n");
        CPPSource.addSource("\tc = c + line");
        CPPSource.addRawSource("\t}\n");
        CPPSource.addSource("f"+std::to_string(Gotos.getI())+".close();\n\t"+variable+" = " + "c");
        return;
    }

}

void write_all_text_to_file(std::vector<std::string> args)
{
    std::string variable = args[1];
    std::string name = args[2];

    char start = variable.at(0);
    char end = variable.at(variable.size()-1);

    char nstart = name.at(0);
    char nend = name.at(name.size()-1);

    if (nstart == '"' && nend == '"')
    {
        if (!Variables.isCpp()) name = name.substr(1, name.size());
    }
    else if (Variables.existsStringVariable(name))
    {
        if (!Variables.isCpp()) name = Variables.getStringVariable(name).getStringValue();
    }
    else
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ WRF ]:[ NOTFOUND:",name," ] String-Variable nicht gefunden!");
    }

    if (start == '[' && end == ']')
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ WRF ] Der Name darf keine Zahl sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (start == '"' && end == '"')
    {
        if (!Variables.isCpp())
        {
            std::fstream f;
            f.open(name, std::ios::out);

            f << variable.substr(1, variable.size()-2) << std::endl;
            f.close();
        }

        CPPSource.addRawSource("\n\tf.open("+name+", std::ios::out);");
        CPPSource.addRawSource("\tf << "+variable+" << std::endl;\n\tf.close();");
        return;
    }

    else if (Variables.existsIntegerVariable(variable))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ WRF ] Der Name darf keine Integer Variable sein, sondern muss ein String sein!");
        exit(0);
    }

    else if (!Variables.existsStringVariable(variable))
    {
        Error.printErr("[ MAIN ]:[ FILESYSTEM ]:[ WRF ]:[ NOTFOUND:",name," ] Die String_Variable existiert nicht!");
        exit(0);
    }

    else if (Variables.existsStringVariable(variable))
    {
        if (!Variables.isCpp())
        {
            std::fstream f;
            f.open(name, std::ios::out);

            f << Variables.getStringVariable(variable).getStringValue() << std::endl;
            f.close();
        }

        CPPSource.addRawSource("\n\tf.open("+name+", std::ios::out);");
        CPPSource.addRawSource("\tf << "+variable+" << std::endl;\n\tf.close();");
        return;
    }


}

#endif //TEST_FILESYSTEM_H
