//
// Created by admin on 2019/3/14.
//

#include "word_chain_model.h"

int WordChainModel::char_to_index(const char &ch) {
    return ch - 'a' + 1;
}

char WordChainModel::index_to_char(const int &index) {
    return (char) ('a' + index - 1);
}

WordChainModel::WordChainModel(const std::vector<std::string> &words) {
    this->words = std::vector<std::string>(words);
}

WordChainModel::WordChainModel(const std::initializer_list<std::string> &words)
        : WordChainModel(std::vector<std::string>(words)) {}

void WordChainModel::init() {
    for (int i = 1; i <= ALPHA_COUNT; i++) {
        graph.add_edge(START_NODE, START_ALPHA_NODE(i), 0);
        graph.add_edge(END_ALPHA_NODE(i), END_NODE, 0);
    }
    auto length = words.size();
    for (int i = 0; i < length; i++) {
        int word_index = i + 1;
        int word_node_index = WORD_NODE(word_index);
        std::string word = words[i];

        char prefix_char = word.at(0);
        int prefix_char_index = char_to_index(prefix_char);
        int prefix_char_node_index = START_ALPHA_NODE(prefix_char_index);
        graph.add_edge(prefix_char_node_index, word_node_index, get_word_weight(word));

        char suffix_char = word.at(word.length() - 1);
        int suffix_char_index = char_to_index(suffix_char);
        int suffix_char_node_index = END_ALPHA_NODE(suffix_char_index);
        graph.add_edge(word_node_index, suffix_char_node_index, 0);
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i == j) continue;
            int word_index_i = i + 1;
            int word_node_index_i = WORD_NODE(word_index_i);
            std::string word_i = words[i];

            int word_index_j = j + 1;
            int word_node_index_j = WORD_NODE(word_index_j);
            std::string word_j = words[j];

            if (word_i.at(word_i.length() - 1) != word_j.at(0)) continue;
            graph.add_edge(word_node_index_i, word_node_index_j, word_j.length());
        }
    }
}

std::vector<std::string> *WordChainModel::get_longest_chain(char start_char, char end_char) {
    int start_node = (start_char == NO_START_CHAR) ? START_NODE : START_ALPHA_NODE(char_to_index(start_char));
    int end_node = (end_char == NO_END_CHAR) ? END_NODE : END_ALPHA_NODE(char_to_index(end_char));
    std::vector<int> *node_link = graph.search_longest_unique_path(start_node, end_node);
    if (node_link == nullptr) {
        return nullptr;
    } else {
        std::vector<int> node_list = *node_link;
        std::vector<std::string> word_list;
        for (const int &node_index : node_list) {
            if (IS_WORD_NODE(node_index)) {
                int word_index = WORD_NODE_TO_INDEX(node_index);
                word_list.emplace_back(words[word_index - 1]);
            }
        }
        return new std::vector<std::string>(word_list);
    }
}