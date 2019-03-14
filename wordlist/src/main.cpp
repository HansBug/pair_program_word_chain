#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <unordered_set>
#include <cctype>       // isalpha
#include <cstring>      // strcpy
#include "../lib/getopt_pp/getopt_pp.h"
#include "error.h"
// Change this if necessary
#include "../../core/src/core.h"    
// For MSVC(VS2017)
// #pragma (lib, "C:/Desktop/pair_program_word_chain/core/build/libCORE_LIB.dll")
#define DEBUG true

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
    if (!flag_w && !flag_c) {
        error(ERR_MISSING_OPTION_W_C);
    } else if (flag_w && flag_c) {
        error(ERR_DUPLICATE_OPTION_W_C);
    }
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
            word << (char)std::tolower(ch);
            empty = false;
        } else if (!empty) {
            words_set.insert(word.str());
            word.str("");
            empty = true;
        }
    }
    if (!empty) {
        words_set.insert(word.str());
    }

    if (words_set.empty()) {
        error(ERR_NO_VALID_WORDS);
    }

    words.insert(words.end(), words_set.begin(), words_set.end());
}

/**
 * Read english words from an input stream
 * 
 * Result is stored into `words`
 */
int readWords2(char *words[], std::istream &input_stream)
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
            word << (char)std::tolower(ch);
            empty = false;
        } else if (!empty) {
            words_set.insert(word.str());
            word.str("");
            empty = true;
        }
    }
    if (!empty) {
        words_set.insert(word.str());
    }

    if (words_set.empty()) {
        error(ERR_NO_VALID_WORDS);
    }
    
    int count = 0;
    for (std::string word : words_set) {
        //https://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c
        // TODO: find a better way to handle memory leak here !!!
        char * w = new char [word.length()+1];
        strcpy(w, word.c_str());
        assert(*(w + word.length()) == '\0');
        words[count++] = w;
    }
    
    return count;
}

int main(int argc, char *argv[])
{
    std::string filename = "../input.txt";
    //std::vector<std::string> words;
    char* words[20000]; // 20000 * 4 bytes ≈ 80 MB 
    int words_count;
    GetOpt::GetOpt_pp ops(argc, argv);

    // Step 1: get filename
    if (!(ops >> GetOpt::GlobalOption(filename))) {
        std::cout << "Not providing input file, ";
        std::cout << "using default file: " << filename << std::endl;
    }

    // Step 2: read file in to words array
    char ch;
    std::ifstream fin(filename, std::fstream::in);
    if (!fin.is_open()) {
        std::cout << "filename: " << filename << std::endl;
        error(ERR_FAILED_OPEN_FILE);
    }
    words_count = readWords2(words, fin);
    fin.close();

    // Step 3: get parameters
    Params params = parseArguments(ops);

    if (DEBUG) {
        std::cout << "Pre-processed words: " << words_count << std::endl;;
        for (int i = 0; i < words_count; i++) {
            std::cout << words[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }

    char* result[10000];

    int result_count;  // result is words count if success, else error code.
    assert( params.flag_c ^ params.flag_w );
    if (params.flag_c) {
        result_count = gen_chain_char(words, words_count, result, params.flag_h, params.flag_t, params.flag_r);
    } else { // params.flag_w
        result_count = gen_chain_word(words, words_count, result, params.flag_h, params.flag_t, params.flag_r);
    }

    // check if success
    if (result_count <= 0) {
        switch (result_count)
        {
            case CORE_WORDS_HAS_CIRCLE:
                error(ERR_UNEXPECTED_CIRCLE_IN_WORDS);
                break;
            case CORE_NO_WORD_CHAIN:
                error(ERR_NO_WORD_CHAIN);
                break;
            case CORE_NO_MATCHED_WORD_CHAIN:
                error(ERR_NO_MATCHED_WORD_CHAIN);
                break;
            case CORE_WORDS_HAS_EMPTY:
                error(ERR_NO_VALID_WORDS);
                break;
            case CORE_WORDS_HAS_INVALID:
                error("unexpected: words have invalid character");
                break;
            default:
                std::cout << "unknown code:" << result_count << std::endl;
                error("unexpected: unknown code");
                break;
        }
    }

    for (int i = 0; i < result_count; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;    
}