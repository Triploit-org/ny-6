//
// Created by survari on 06.11.16.
//

#ifndef TEST_LANGVARS_HPP
#define TEST_LANGVARS_HPP

#include <iostream>
#include <vector>
#include "objects/Command.hpp"
#include "cmds/Define.hpp"
#include "cmds/Mov.hpp"
#include "cmds/Output.hpp"
#include "objects/Goto.hpp"
#include "cmds/Maths.hpp"
#include "cmds/EqualsInt.hpp"
#include "cmds/EqualsString.hpp"
#include "cmds/Input.hpp"
#include "cmds/StringOps.hpp"
#include "cmds/IfDefInc.hpp"
#include "cmds/FileSystem.h"

class System
{
private:
    int line = 0;
    std::vector<Command> commands;


public:

    int getOSNumber()
    {
        #ifdef _WIN32
            return 0;
        #elif _WIN64
            return 1;
        #elif __unix || __unix__
            return 2;
        #elif __APPLE__ || __MACH__
            return 3;
        #elif __linux__
            return 4;
        #elif __FreeBSD__
            return 5;
        #else
            return 6;
        #endif
    }

    void addCommand(Command c)
    {
        commands.push_back(c);
    }

    void incrementLine()
    {
        line--;
    }

    void addLineCount()
    {
        line++;
    }

    int getLine()
    {
        return line;
    }

    void printError(std::string s)
    {
        std::cout << "[ " << line << " ] " << s;
    }

    std::vector<Command> getCommands()
    {
        return commands;
    }

    void initCommands()
    {
        Command moi;
        moi.setName("moi");
        moi.setFunction(move_integer);
        moi.setArgCount(2);

        Command mos;
        mos.setName("mos");
        mos.setFunction(move_string);
        mos.setArgCount(2);

        Command defi;
        defi.setName("defi");
        defi.setFunction(define_int);
        defi.setArgCount(2);

        Command defs;
        defs.setName("defs");
        defs.setFunction(define_string);
        defs.setArgCount(2);


        Command prv;
        prv.setName("prv");
        prv.setFunction(print_value);
        prv.setArgCount(1);

        Command say;
        say.setName("say");
        say.setFunction(say_text);
        say.setArgCount(1);

        Command add;
        add.setName("add");
        add.setFunction(add_variable);
        add.setArgCount(2);

        Command sub;
        sub.setName("sub");
        sub.setFunction(sub_variable);
        sub.setArgCount(2);

        Command mul;
        mul.setName("mul");
        mul.setFunction(mul_variable);
        mul.setArgCount(2);

        Command div;
        div.setName("div");
        div.setFunction(div_variable);
        div.setArgCount(2);

        Command eqi;
        eqi.setName("eqi");
        eqi.setFunction(equals_equals_int);
        eqi.setArgCount(3);

        Command nqi;
        nqi.setName("nqi");
        nqi.setFunction(not_equals_int);
        nqi.setArgCount(3);

        Command lqi;
        lqi.setName("lqi");
        lqi.setFunction(less_equals_int);
        lqi.setArgCount(3);

        Command gqi;
        gqi.setName("gqi");
        gqi.setFunction(greater_equals_int);
        gqi.setArgCount(3);

        Command eqs;
        eqs.setName("eqs");
        eqs.setFunction(equals_equals_str);
        eqs.setArgCount(3);

        Command nqs;
        nqs.setName("nqs");
        nqs.setFunction(not_equals_str);
        nqs.setArgCount(3);

        Command lqs;
        lqs.setName("lqs");
        lqs.setFunction(less_equals_str);
        lqs.setArgCount(3);

        Command gqs;
        gqs.setName("gqs");
        gqs.setFunction(greater_equals_str);
        gqs.setArgCount(3);

        Command inp;
        inp.setName("inp");
        inp.setFunction(input_variable);
        inp.setArgCount(1);

        Command sti;
        sti.setName("sti");
        sti.setFunction(sti_int);
        sti.setArgCount(2);

        Command gca;
        gca.setName("gca");
        gca.setFunction(gca_string);
        gca.setArgCount(3);

        Command err;
        err.setName("%err");
        err.setFunction(prae_error);
        err.setArgCount(1);

        Command poi;
        poi.setName("poi");
        poi.setFunction(poi_variable);
        poi.setArgCount(2);

        Command mod;
        mod.setName("mod");
        mod.setFunction(mod_variable);
        mod.setArgCount(2);

        Command cnd;
        cnd.setName("cnd");
        cnd.setFunction(create_new_directory);
        cnd.setArgCount(1);

        Command cnf;
        cnf.setName("cnf");
        cnf.setFunction(create_new_file);
        cnf.setArgCount(1);

        Command dd;
        dd.setName("dd");
        dd.setFunction(delete_directory);
        dd.setArgCount(1);

        Command df;
        df.setName("df");
        df.setFunction(delete_file);
        df.setArgCount(1);

        Command rtf;
        rtf.setName("rtf");
        rtf.setFunction(read_all_text_from_file);
        rtf.setArgCount(2);

        Command wrf;
        wrf.setName("wrf");
        wrf.setFunction(write_all_text_to_file);
        wrf.setArgCount(2);

        Command chd;
        chd.setName("chd");
        chd.setFunction(change_directory);
        chd.setArgCount(1);

        commands.push_back(moi);
        commands.push_back(mos);
        commands.push_back(defi);
        commands.push_back(defs);
        commands.push_back(prv);
        commands.push_back(say);
        commands.push_back(add);
        commands.push_back(sub);
        commands.push_back(div);
        commands.push_back(mul);
        commands.push_back(eqi);
        commands.push_back(nqi);
        commands.push_back(lqi);
        commands.push_back(gqi);
        commands.push_back(eqs);
        commands.push_back(gqs);
        commands.push_back(lqs);
        commands.push_back(nqs);
        commands.push_back(inp);
        commands.push_back(sti);
        commands.push_back(gca);
        commands.push_back(err);
        commands.push_back(poi);
        commands.push_back(mod);
        commands.push_back(cnf);
        commands.push_back(cnd);
        commands.push_back(dd);
        commands.push_back(df);
        commands.push_back(wrf);
        commands.push_back(rtf);
        commands.push_back(chd);
    }
} System;

#endif //TEST_LANGVARS_HPP
