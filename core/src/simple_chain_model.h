//
// Created by admin on 2019/3/12.
//

#ifndef CORE_SIMPLE_CHAIN_MODEL_H
#define CORE_SIMPLE_CHAIN_MODEL_H

#include <string>
#include <vector>

class SimpleChainModel {
private:

protected:
    virtual int get_word_weight(const std::string &string) = 0;

public:

};

#endif //CORE_SIMPLE_CHAIN_MODEL_H
