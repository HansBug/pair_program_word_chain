//
// Created by admin on 2019/3/12.
//

#ifndef CORE_SIMPLE_CHAIN_WORD_H
#define CORE_SIMPLE_CHAIN_WORD_H

#include "string_process.h"
#include "graph_process.h"
#include <vector>
#include <string>

class SimpleChainWordSolution {
private:
    std::vector<std::string> words;
public:
    SimpleChainWordSolution() = default;

    explicit SimpleChainWordSolution(const std::vector<std::string> &words) {
        this->words = std::vector<std::string>(words);
    }
};

#endif //CORE_SIMPLE_CHAIN_WORD_H
