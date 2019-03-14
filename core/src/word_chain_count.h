//
// Created by admin on 2019/3/14.
//

#ifndef CORE_WORD_CHAIN_COUNT_H
#define CORE_WORD_CHAIN_COUNT_H

#include "word_chain_model.h"

class WordChainCountModel : public WordChainModel {
protected:
    int get_word_weight(const std::string &word) override;

public:
    explicit WordChainCountModel(const std::vector<std::string> &words) : WordChainModel(words) {};

    WordChainCountModel(const std::initializer_list<std::string> &words) : WordChainModel(words) {};
};

#endif //CORE_WORD_CHAIN_COUNT_H
