//
// Created by admin on 2019/3/12.
//

#ifndef CORE_SIMPLE_CHAIN_MODEL_H
#define CORE_SIMPLE_CHAIN_MODEL_H

#include <string>
#include <vector>
#include <unordered_map>
#include <initializer_list>
#include "graph_process.h"

#define NO_START_CHAR   (0)
#define NO_END_CHAR     (0)

#define ALPHA_COUNT             (26)

#define SIMPLE_START_NODE              (1)
#define SIMPLE_FIRST_ALPHA_START_NODE  (SIMPLE_START_NODE + 1)
#define SIMPLE_ALPHA_START_NODE(INDEX) (SIMPLE_FIRST_ALPHA_START_NODE + INDEX - 1)
#define SIMPLE_LAST_ALPHA_START_NODE   (SIMPLE_ALPHA_START_NODE(ALPHA_COUNT))

#define SIMPLE_END_NODE                (SIMPLE_LAST_ALPHA_START_NODE + 1)
#define SIMPLE_FIRST_ALPHA_END_NODE    (SIMPLE_END_NODE + 1)
#define SIMPLE_ALPHA_END_NODE(INDEX)   (SIMPLE_FIRST_ALPHA_END_NODE + INDEX - 1)
#define SIMPLE_LAST_ALPHA_END_NODE     (SIMPLE_ALPHA_END_NODE(ALPHA_COUNT))

#define SIMPLE_MAX_WORD_COUNT              (10010)
#define SIMPLE_FIRST_WORD_NODE             (SIMPLE_LAST_ALPHA_END_NODE + 1)
#define SIMPLE_WORD_NODE(INDEX)            (SIMPLE_FIRST_WORD_NODE + INDEX - 1)
#define SIMPLE_IS_WORD_NODE(NODE_INDEX)    (NODE_INDEX >= SIMPLE_FIRST_WORD_NODE)
#define SIMPLE_TO_WORD_INDEX(NODE_INDEX)   (NODE_INDEX - SIMPLE_FIRST_WORD_NODE + 1)
#define SIMPLE_MAX_WORD_NODE               (SIMPLE_WORD_NODE(SIMPLE_MAX_WORD_COUNT))
#define SIMPLE_MAX_NODE_COUNT              (SIMPLE_MAX_WORD_NODE)

class SimpleChainModel {
private:
    std::vector<std::string> words;
    Graph<SIMPLE_MAX_NODE_COUNT> graph;

    // turn char into graph node index
    int char_to_index(const char &ch);

    // turn graph node index into char
    char index_to_char(const int &index);

protected:
    virtual int get_word_weight(const std::string &string) = 0;

public:
    explicit SimpleChainModel(const std::vector<std::string> &words);

    SimpleChainModel(const std::initializer_list<std::string> &words);

    void init();

    std::vector<std::string> *get_longest_link();

    std::vector<std::string> *get_longest_link_start_with(char start_with);

    std::vector<std::string> *get_longest_link_end_with(char end_with);

    std::vector<std::string> *get_longest_link(char start_with, char end_with);

    bool has_word_circle();
};

#endif //CORE_SIMPLE_CHAIN_MODEL_H
