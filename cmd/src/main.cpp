#include <iostream>
#include <stdio.h>
#include <cassert>
#include "../lib/getopt_pp/getopt_pp.h"
// #include "../../core/core.h"
// #pragma comment(lib, "C:/Desktop/pair_program_word_chain/core/build/libcore")



int main(int argc, char *argv[])
{
    bool flag_w, flag_c, flag_h, flag_t, flag_r;
    std::string filename;

    // Step 1: parse parameters
    GetOpt::GetOpt_pp ops(argc, argv);
    ops >> GetOpt::OptionPresent('w', flag_w);
    ops >> GetOpt::OptionPresent('c', flag_c);
    ops >> GetOpt::OptionPresent('h', flag_h);
    ops >> GetOpt::OptionPresent('t', flag_t);
    ops >> GetOpt::OptionPresent('r', flag_r);
    ops >> GetOpt::GlobalOption(filename);
    printf("w:%d, c:%d, h:%d, t:%d, r:%d\n", 
        flag_w, flag_c, flag_h, flag_t, flag_r);
    printf("filename:%s\n", filename.c_str());

    // Step 2: read file

    return 0;    
}