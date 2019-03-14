//
// Created by admin on 2019/3/14.
//

#ifndef CORE_WORD_CHAIN_MODEL_H
#define CORE_WORD_CHAIN_MODEL_H

#include "graph_process.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

#define ALPHA_COUNT                 (26)

#define WORD_START_NODE                  (1)
#define WORD_FIRST_START_ALPHA_NODE      (WORD_START_NODE + 1)
#define WORD_START_ALPHA_NODE(INDEX)     (WORD_FIRST_START_ALPHA_NODE + INDEX - 1)
#define WORD_LAST_START_ALPHA_NODE       (WORD_START_ALPHA_NODE(ALPHA_COUNT))

#define WORD_END_NODE                    (WORD_LAST_START_ALPHA_NODE + 1)
#define WORD_FIRST_END_ALPHA_NODE        (WORD_END_NODE + 1)
#define WORD_END_ALPHA_NODE(INDEX)       (WORD_FIRST_END_ALPHA_NODE + INDEX - 1)
#define WORD_LAST_END_ALPHA_NODE         (WORD_END_ALPHA_NODE(ALPHA_COUNT))

#define WORD_FIRST_WORD_NODE             (WORD_LAST_END_ALPHA_NODE + 1)
#define WORD_WORD_NODE(INDEX)            (WORD_FIRST_WORD_NODE + INDEX - 1)
#define WORD_LAST_WORD_NODE(WORD_COUNT)  (WORD_WORD_NODE(WORD_COUNT))
#define WORD_NODE_COUNT(WORD_COUNT)      (WORD_LAST_WORD_NODE(WORD_COUNT))
#define WORD_IS_WORD_NODE(NODE_INDEX)    (NODE_INDEX >= WORD_FIRST_WORD_NODE)
#define WORD_WORD_NODE_TO_INDEX(NODE_INDEX)  (NODE_INDEX - WORD_FIRST_WORD_NODE + 1)

#define WORD_MAX_WORD_LIMIT              (150)
#define WORD_MAX_NODE_LIMIT              (WORD_NODE_COUNT(WORD_MAX_WORD_LIMIT))

#define NO_START_CHAR               (0)
#define NO_END_CHAR                 (0)

class WordChainModel {
private:
    std::vector<std::string> words;
    Graph<WORD_MAX_NODE_LIMIT> graph;

    int char_to_index(const char &ch);

    char index_to_char(const int &index);

protected:
    virtual int get_word_weight(const std::string &word) = 0;

public:
    explicit WordChainModel(const std::vector<std::string> &words);

    WordChainModel(const std::initializer_list<std::string> &words);

    void init();

    std::vector<std::string> *get_longest_chain(char start_char, char end_char);
};

#endif //CORE_WORD_CHAIN_MODEL_H
