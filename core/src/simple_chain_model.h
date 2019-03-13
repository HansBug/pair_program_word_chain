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
#define NO_START_CHAR   (0)
#define NO_END_CHAR     (0)

class SimpleChainModel {
private:
    std::vector<std::string> words;
    std::unordered_map<std::string, std::string> storage;
    Graph<MAX_ALPHA_INDEX> graph;

    // generate key from prefix char and suffix char
    std::string prefix_and_suffix_to_key(const char &prefix, const char &suffix);

    // generate key from string's prefix and suffix
    std::string prefix_and_suffix_to_key(const std::string &string);

    // set string into graph
    void put_string(const std::string &string);

    // get string from prefix and suffix
    std::string *get_string(const char &prefix, const char &suffix);

    // turn char into graph node index
    int char_to_index(const char &ch);

    // turn graph node index into char
    char index_to_char(const int &index);

    // initialize this model
    void init_model(const std::vector<std::string> &strings);

protected:
    virtual int get_word_weight(const std::string &string) = 0;

public:
    explicit SimpleChainModel(const std::vector<std::string> &strings);

    SimpleChainModel(const std::initializer_list<std::string> &strings);

    void init();

    std::vector<std::string> *get_longest_link();

    std::vector<std::string> *get_longest_link_start_with(char start_with);

    std::vector<std::string> *get_longest_link_end_with(char end_with);

    std::vector<std::string> *get_longest_link(char start_with, char end_with);

    bool has_word_circle();
};

#endif //CORE_SIMPLE_CHAIN_MODEL_H
