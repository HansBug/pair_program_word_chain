//
// Created by admin on 2019/3/12.
//

#include <sstream>
#include "simple_chain_model.h"

int SimpleChainModel::char_to_index(const char &ch) {
    return ch - 'a' + 1;
}


SimpleChainModel::SimpleChainModel(const std::vector<std::string> &words) {
    this->words = std::vector<std::string>(words);
}

void SimpleChainModel::init() {
    auto length = words.size();
    std::unordered_map<char, std::vector<int>> prefix_sorted;
    for (char c = 'a'; c <= 'z'; c++) {
        prefix_sorted[c] = std::vector<int>();
        graph.add_edge(SIMPLE_START_NODE, SIMPLE_ALPHA_START_NODE(char_to_index(c)), 0);
        graph.add_edge(SIMPLE_ALPHA_END_NODE(char_to_index(c)), SIMPLE_END_NODE, 0);
    }
    for (int i = 0; i < length; i++) {
        std::string word = words[i];
        int word_index = i + 1;

        char prefix = word.at(0);
        prefix_sorted[prefix].emplace_back(i);
        graph.add_edge(SIMPLE_ALPHA_START_NODE(char_to_index(prefix)), SIMPLE_WORD_NODE(word_index),
                       get_word_weight(word));

        char suffix = word.at(word.length() - 1);
        graph.add_edge(SIMPLE_WORD_NODE(word_index), SIMPLE_ALPHA_END_NODE(char_to_index(suffix)), 0);
    }
    for (int i = 0; i < length; i++) {
        int word_index_i = i + 1;
        std::string word_i = words[i];
        char suffix_i = word_i.at(word_i.length() - 1);
        for (const int &j : prefix_sorted[suffix_i]) {
            if (i == j) continue;
            int word_index_j = j + 1;
            std::string word_j = words[j];
            graph.add_edge(SIMPLE_WORD_NODE(word_index_i), SIMPLE_WORD_NODE(word_index_j), get_word_weight(word_j));
        }
    }
}
std::vector<std::string> *SimpleChainModel::get_longest_link(char start_with, char end_with) {
    int start_node = (start_with == NO_START_CHAR) ? SIMPLE_START_NODE : SIMPLE_ALPHA_START_NODE(
            char_to_index(start_with));
    int end_node = (end_with == NO_END_CHAR) ? SIMPLE_END_NODE : SIMPLE_ALPHA_END_NODE(char_to_index(end_with));

    std::vector<int> *link = graph.get_longest_path(start_node, end_node);

    if (link == nullptr) {
        return nullptr;
    } else {
        auto *result = new std::vector<std::string>();
        for (const int &node_index : *link) {
            if (SIMPLE_IS_WORD_NODE(node_index)) {
                int word_index = SIMPLE_TO_WORD_INDEX(node_index);
                result->emplace_back(words[word_index - 1]);
            }
        }
        return result;
    }
}
