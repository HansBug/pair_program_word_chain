//
// Created by admin on 2019/3/12.
//

#include <sstream>
#include "simple_chain_model.h"

std::string SimpleChainModel::prefix_and_suffix(const char &prefix, const char &suffix) {
    std::stringstream stream;
    stream << prefix << suffix;
    return stream.str();
}

std::string SimpleChainModel::prefix_and_suffix(const std::string &string) {
    return prefix_and_suffix(string.at(0), string.at(string.length() - 1));
}

void SimpleChainModel::put_string(const std::string &string) {
    std::string key = prefix_and_suffix(string);
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
    std::string key = prefix_and_suffix(prefix, suffix);
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
                std::cout << i << ' ' << j << " " << weight << std::endl;
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
    return get_longest_link(NO_START_CHAR);
}

std::vector<std::string> *SimpleChainModel::get_longest_link(char start_with) {
    std::vector<int> *link;
    if (start_with == NO_START_CHAR) {
        link = graph.get_longest_path();
    } else {
        link = graph.get_longest_path(char_to_index(start_with));
    }

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