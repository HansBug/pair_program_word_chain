//
// Created by admin on 2019/3/11.
//

#include "string_process.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <iostream>

// turn word array ptr to string vector
std::vector<std::string> char_array_ptr_to_vector(char *words[], int len) {
    std::vector<std::string> result;
    result.reserve((unsigned int) len);
    for (int i = 0; i < len; i++) {
        std::string word = std::string(words[i]);
        result.emplace_back(word);
    }
    return result;
}

// turn string vector to char array ptr
int vector_to_char_array_ptr(const std::vector<std::string> &words, char *result[]) {
    auto len = words.size();
    for (int i = 0; i < len; i++) {
        std::string word = words[i];
        auto word_length = word.length();
        result[i] = new char[word_length + 1];
        strcpy(result[i], word.c_str());
    }
    return len;
}