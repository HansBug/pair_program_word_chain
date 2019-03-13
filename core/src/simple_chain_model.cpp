//
// Created by admin on 2019/3/12.
//

#include <sstream>
#include "simple_chain_model.h"

std::string SimpleChainModel::prefix_and_suffix_to_key(const char &prefix, const char &suffix) {
    std::stringstream stream;
    stream << prefix << suffix;
    return stream.str();
}

std::string SimpleChainModel::prefix_and_suffix_to_key(const std::string &string) {
    return prefix_and_suffix_to_key(string.at(0), string.at(string.length() - 1));
}

void SimpleChainModel::put_string(const std::string &string) {
    std::string key = prefix_and_suffix_to_key(string);
    if (storage.find(key) != storage.end()) {
        std::string old_string = storage[key];
        if (string.length() > old_string.length()) {
            storage[key] = string;
        }
    } else {
        storage[key] = string;
    }
}

std::string *SimpleChainModel::get_string(const char &prefix, const char &suffix) {
    std::string key = prefix_and_suffix_to_key(prefix, suffix);
    if (storage.find(key) != storage.end()) {
        return new std::string(storage[key]);
    } else {
        return nullptr;
    }
}

int SimpleChainModel::char_to_index(const char &ch) {
    return ch - 'a' + 1;
}

char SimpleChainModel::index_to_char(const int &index) {
    return (char) ('a' + index - 1);
}

void SimpleChainModel::init_model(const std::vector<std::string> &strings) {
    for (const std::string &string : strings) {
        put_string(string);
    }
    for (int i = 1; i <= MAX_ALPHA_INDEX; i++) {
        for (int j = 1; j <= MAX_ALPHA_INDEX; j++) {
            char prefix = index_to_char(i);
            char suffix = index_to_char(j);
            std::string *str = get_string(prefix, suffix);
            if (str != nullptr) {
                int weight = get_word_weight(*str);
                graph.add_edge(i, j, weight);
            }
        }
    }
}

SimpleChainModel::SimpleChainModel(const std::vector<std::string> &strings) {
    words.insert(words.end(), strings.begin(), strings.end());
}

SimpleChainModel::SimpleChainModel(const std::initializer_list<std::string> &strings)
        : SimpleChainModel(std::vector<std::string>(strings)) {}

void SimpleChainModel::init() {
    init_model(words);
}

std::vector<std::string> *SimpleChainModel::get_longest_link() {
    return get_longest_link(NO_START_CHAR, NO_END_CHAR);
}

std::vector<std::string> *SimpleChainModel::get_longest_link_start_with(char start_with) {
    return get_longest_link(start_with, NO_END_CHAR);
}

std::vector<std::string> *SimpleChainModel::get_longest_link_end_with(char end_with) {
    return get_longest_link(NO_START_CHAR, end_with);
}

std::vector<std::string> *SimpleChainModel::get_longest_link(char start_with, char end_with) {
    int start_index = NO_START_NODE;
    int end_index = NO_END_NODE;

    if (start_with != NO_START_CHAR) {
        start_index = char_to_index(start_with);
    }
    if (end_with != NO_END_CHAR) {
        end_index = char_to_index(end_with);
    }
    std::vector<int> *link = graph.get_longest_path(start_index, end_index);

    if (link == nullptr) {
        return nullptr;
    }

    std::vector<std::string> result;
    std::vector<int> list = *link;
    auto length = list.size();
    for (int i = 0; i + 1 < length; i++) {
        int u = list[i];
        int v = list[i + 1];
        char prefix = index_to_char(u);
        char suffix = index_to_char(v);
        std::string *str = get_string(prefix, suffix);
        result.insert(result.end(), *str);
    }

    return new std::vector<std::string>(result);
}

bool SimpleChainModel::has_word_circle() {
    return graph.has_circle();
}