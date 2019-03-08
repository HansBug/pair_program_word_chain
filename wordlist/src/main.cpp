#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <unordered_set>
#include <cctype>
#include "../lib/getopt_pp/getopt_pp.h"
#include "error.h"
// #include "../../core/core.h"
// #pragma comment(lib, "C:/Desktop/pair_program_word_chain/core/build/libcore")

typedef struct _Params {
    bool flag_w, flag_c;
    char flag_h, flag_t;
    bool flag_r;
} Params;


Params parseArguments(GetOpt::GetOpt_pp &ops) 
{
    bool flag_w, flag_c;
    char flag_h, flag_t;
    bool flag_r;

    //GetOpt::GetOpt_pp ops(argc, argv);
    ops >> GetOpt::OptionPresent('w', flag_w);
    ops >> GetOpt::OptionPresent('c', flag_c);
    if (ops >> GetOpt::OptionPresent('h')) {
        if (!(ops >> GetOpt::Option('h', flag_h))) {
            error(ERR_WRONG_FORMAT_OPTION_H);
        }
    }
    if (ops >> GetOpt::OptionPresent('t')) {
        if (!(ops >> GetOpt::Option('t', flag_t))) {
            error(ERR_WRONG_FORMAT_OPTION_T);
        }
    }
    ops >> GetOpt::OptionPresent('r', flag_r);
    /*
    printf("w:%d, c:%d, h:%d, t:%d, r:%d\n", 
        flag_w, flag_c, flag_h, flag_t, flag_r);
    printf("filename: %s\n", filename.c_str());
    */
   return Params{flag_w, flag_c, flag_h, flag_t, flag_r};
}


/**
 * Read english words from an input stream
 * 
 * Result is stored into `words`
 */
void readWords(std::vector<std::string> &words, std::istream &input_stream)
{
    char ch;
    bool empty = true;
    std::stringstream word;   
    std::unordered_set<std::string> words_set;

    /**
     * TODO: 
     * which is faster ?
     * stringstream's << operator and string's + operter
     */

    // read char by char
    while (input_stream >> std::noskipws >> ch) {
        if (std::isalpha(ch)) {
            assert(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
            word << (char)std::tolower(ch);
            empty = false;
        } else if (!empty) {
            words_set.insert(word.str());
            word.str("");
            empty = true;
        }
    }

    if (words_set.empty()) {
        error(ERR_NO_VALID_WORDS);
    }

    words.insert(words.end(), words_set.begin(), words_set.end());
}


int main(int argc, char *argv[])
{
    std::string filename = "../input.txt";
    std::vector<std::string> words;
    GetOpt::GetOpt_pp ops(argc, argv);

    if (!(ops >> GetOpt::GlobalOption(filename))) {
        std::cout << "Not providing input file, ";
        std::cout << "using default file: " << filename << std::endl;
    }

    // Step 2: read file char by char
    char ch;
    std::ifstream fin(filename, std::fstream::in);
    if (!fin.is_open()) {
        std::cout << "filename: " << filename << std::endl;
        error(ERR_FAILED_OPEN_FILE);
    }
    readWords(words, fin);
    fin.close();

    Params params = parseArguments(ops);
    for (std::string word : words) {
        std::cout << word << " " << std::endl;
    }

    return 0;    
}