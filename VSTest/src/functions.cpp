//
// Created by admin on 2019/3/13.
//

#include "functions.h"

// check if words is valid
int words_precheck(const std::vector<std::string> &words) {
    for (const std::string &word : words) {

        char prefix = word.at(0);
        char suffix = word.at(word.length() - 1);

    }
    return SUCCESS;
}


int get_chain_with_word(const std::vector<std::string> &words, std::vector<std::string> *&link,
                        const char &start_with, const char &end_with) {
    int ret = words_precheck(words);


    auto model = SimpleChainCountModel(words);
    model.init();


    link = model.get_longest_link(start_with, end_with);

        return SUCCESS;
 
}

int get_chain_with_char(const std::vector<std::string> &words, std::vector<std::string> *&link,
                        const char &start_with, const char &end_with) {
    int ret = words_precheck(words);


    auto model = SimpleChainWordModel(words);
    model.init();


    link = model.get_longest_link(start_with, end_with);

        return SUCCESS;

}

int get_chain_with_word_allow_same(const std::vector<std::string> &words, std::vector<std::string> *&link,
                                   const char &start_with, const char &end_with) {
    int ret = words_precheck(words);


    auto model = WordChainCountModel(words);
    model.init();
    link = model.get_longest_chain(start_with, end_with);

        return SUCCESS;

}

int get_chain_with_char_allow_same(const std::vector<std::string> &words, std::vector<std::string> *&link,
                                   const char &start_with, const char &end_with) {
    int ret = words_precheck(words);

    auto model = WordChainWordModel(words);
    model.init();
    link = model.get_longest_chain(start_with, end_with);
    if (link != nullptr) {
        return SUCCESS;
    }
}