//
// Created by admin on 2019/3/13.
//

#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H

#include "simple_chain_word.h"
#include "simple_chain_count.h"
#include "word_chain_word.h"
#include "word_chain_count.h"

#define SUCCESS                 (0)
#define WORDS_HAS_CIRCLE        (-1)
#define WORDS_HAS_EMPTY         (-2)
#define WORDS_HAS_INVALID       (-3)
#define WORDS_LINK_NOT_FOUND    (-4)

// check if words is valid
int words_precheck(const std::vector<std::string> &words);

// check if there is word circle
int words_circle_check(const std::vector<std::string> &words);

// get longest word chain with word count
int get_chain_with_word(const std::vector<std::string> &words, std::vector<std::string> *&link,
                        const char &start_with, const char &end_with);

// get longest word chain with word length
int get_chain_with_char(const std::vector<std::string> &words, std::vector<std::string> *&link,
                        const char &start_with, const char &end_with);

int get_chain_with_word_allow_same(const std::vector<std::string> &words, std::vector<std::string> *&link,
                                   const char &start_with, const char &end_with);

int get_chain_with_char_allow_same(const std::vector<std::string> &words, std::vector<std::string> *&link,
                                   const char &start_with, const char &end_with);

#endif //CORE_FUNCTIONS_H
