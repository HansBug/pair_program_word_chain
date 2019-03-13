//
// Created by admin on 2019/3/13.
//

#include "functions.h"

// check if words is valid
int words_precheck(const std::vector<std::string> &words) {
    for (const std::string &word : words) {
        if (word.length() == 0) {
            return WORDS_HAS_EMPTY;
        }
        char prefix = word.at(0);
        char suffix = word.at(word.length() - 1);
        if (prefix < 'a' || prefix > 'z' || suffix < 'a' || suffix > 'z') {
            return WORDS_HAS_INVALID;
        }
    }
    return SUCCESS;
}

int words_circle_check(const std::vector<std::string> &words) {
    int ret = words_precheck(words);
    if (ret) {
        return ret;
    }

    auto model = SimpleChainCountModel(words);
    model.init();
    if (model.has_word_circle()) {
        return WORDS_HAS_CIRCLE;
    }

    return SUCCESS;
}

int get_chain_with_word(const std::vector<std::string> &words, std::vector<std::string> *&link,
                        const char &start_with, const char &end_with) {
    int ret = words_precheck(words);
    if (ret) {
        return ret;
    }

    auto model = SimpleChainCountModel(words);
    model.init();
    if (model.has_word_circle()) {
        return WORDS_HAS_CIRCLE;
    }

    link = model.get_longest_link(start_with, end_with);
    if (link != nullptr) {
        return SUCCESS;
    } else {
        return WORDS_LINK_NOT_FOUND;
    }
}

int get_chain_with_char(const std::vector<std::string> &words, std::vector<std::string> *&link,
                        const char &start_with, const char &end_with) {
    int ret = words_precheck(words);
    if (ret) {
        return ret;
    }

    auto model = SimpleChainWordModel(words);
    model.init();
    if (model.has_word_circle()) {
        return WORDS_HAS_CIRCLE;
    }

    link = model.get_longest_link(start_with, end_with);
    if (link != nullptr) {
        return SUCCESS;
    } else {
        return WORDS_LINK_NOT_FOUND;
    }
}