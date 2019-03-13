//
// Created by admin on 2019/3/12.
//

#ifndef CORE_SIMPLE_CHAIN_WORD_H
#define CORE_SIMPLE_CHAIN_WORD_H

#include "simple_chain_model.h"

class SimpleChainWordModel : public SimpleChainModel {
protected:
    // word's weight
    int get_word_weight(const std::string &string) override;

public:
    // constructor
    explicit SimpleChainWordModel(const std::vector<std::string> &strings) : SimpleChainModel(strings) {}

    // list constructor
    SimpleChainWordModel(const std::initializer_list<std::string> &strings) : SimpleChainModel(strings) {}
};

#endif //CORE_SIMPLE_CHAIN_WORD_H
