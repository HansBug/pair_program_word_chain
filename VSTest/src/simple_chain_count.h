//
// Created by admin on 2019/3/13.
//

#ifndef CORE_SIMPLE_CHAIN_COUNT_H
#define CORE_SIMPLE_CHAIN_COUNT_H

#include "simple_chain_model.h"

class SimpleChainCountModel : public SimpleChainModel {
protected:
    // word's weight
    int get_word_weight(const std::string &string) override;

public:
    // constructor
    explicit SimpleChainCountModel(const std::vector<std::string> &strings) : SimpleChainModel(strings) {}

    // list constructor
    SimpleChainCountModel(const std::initializer_list<std::string> &strings) : SimpleChainModel(strings) {}
};

#endif //CORE_SIMPLE_CHAIN_COUNT_H
