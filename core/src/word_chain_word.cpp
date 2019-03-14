//
// Created by admin on 2019/3/14.
//

#include "word_chain_word.h"

int WordChainWordModel::get_word_weight(const std::string &word) {
    return word.length();
}