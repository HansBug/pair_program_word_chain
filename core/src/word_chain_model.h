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

#define START_NODE                  (1)
#define FIRST_START_ALPHA_NODE      (START_NODE + 1)
#define START_ALPHA_NODE(INDEX)     (FIRST_START_ALPHA_NODE + INDEX - 1)
#define LAST_START_ALPHA_NODE       (START_ALPHA_NODE(ALPHA_COUNT))
#define IS_START_NODE(NODE_INDEX)   ((NODE_INDEX >= FIRST_START_ALPHA_NODE) && (NODE_INDEX <= LAST_START_ALPHA_NODE))

#define END_NODE                    (LAST_START_ALPHA_NODE + 1)
#define FIRST_END_ALPHA_NODE        (END_NODE + 1)
#define END_ALPHA_NODE(INDEX)       (FIRST_END_ALPHA_NODE + INDEX - 1)
#define LAST_END_ALPHA_NODE         (END_ALPHA_NODE(ALPHA_COUNT))
#define IS_END_NODE(NODE_INDEX)     ((NODE_INDEX >= FIRST_END_ALPHA_NODE) && (NODE_INDEX <= LAST_END_ALPHA_NODE))

#define FIRST_WORD_NODE             (LAST_END_ALPHA_NODE + 1)
#define WORD_NODE(INDEX)            (FIRST_WORD_NODE + INDEX - 1)
#define LAST_WORD_NODE(WORD_COUNT)  (WORD_NODE(WORD_COUNT))
#define NODE_COUNT(WORD_COUNT)      (LAST_WORD_NODE(WORD_COUNT))
#define IS_WORD_NODE(NODE_INDEX)    (NODE_INDEX >= FIRST_WORD_NODE)
#define WORD_NODE_TO_INDEX(NODE_INDEX)  (NODE_INDEX - FIRST_WORD_NODE + 1)

#define MAX_WORD_LIMIT              (150)
#define MAX_NODE_LIMIT              (NODE_COUNT(MAX_WORD_LIMIT))

#define NO_START_CHAR               (0)
#define NO_END_CHAR                 (0)

class WordChainModel {
private:
    std::vector<std::string> words;
    Graph<MAX_NODE_LIMIT> graph;

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
