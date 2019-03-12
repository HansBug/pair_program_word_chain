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

#define MAX_ALPHA_INDEX (26)
#define NO_START_CHAR (0)

class SimpleChainModel {
private:
    std::vector<std::string> words;
    std::unordered_map<std::string, std::string> storage;
    Graph<MAX_ALPHA_INDEX> graph;

    std::string prefix_and_suffix(const char &prefix, const char &suffix);

    std::string prefix_and_suffix(const std::string &string);

    void put_string(const std::string &string);

    std::string *get_string(const char &prefix, const char &suffix);

    int char_to_index(const char &ch);

    char index_to_char(const int &index);

    void init_model(const std::vector<std::string> &strings);

protected:
    virtual int get_word_weight(const std::string &string) = 0;

public:
    explicit SimpleChainModel(const std::vector<std::string> &strings);

    SimpleChainModel(const std::initializer_list<std::string> &strings);

    void init();

    std::vector<std::string> *get_longest_link();

    std::vector<std::string> *get_longest_link(char start_with);
};

#endif //CORE_SIMPLE_CHAIN_MODEL_H
