//
// Created by admin on 2019/3/11.
//

#include "string_process.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <iostream>

bool is_downcase(const char &ch) {
    return ch >= 'a' && ch <= 'z';
}

char downcase(const char &ch) {
    if (is_upcase(ch)) {
        return ch - 'A' + 'a';
    } else {
        return ch;
    }
}

// turn string to downcase
std::string downcase(const std::string &string) {
    std::string result(string);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool is_upcase(const char &ch) {
    return ch >= 'A' && ch <= 'Z';
}

char upcase(const char &ch) {
    if (is_downcase(ch)) {
        return ch - 'a' + 'A';
    } else {
        return ch;
    }
}

// turn string to upcase
std::string upcase(const std::string &string) {
    std::string result(string);
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// switch all the words to downcase words
std::vector<std::string> strings_to_downcase(const std::vector<std::string> &strings) {
    std::vector<std::string> result;
    for (const std::string &string : strings) {
        result.insert(result.end(), downcase(string));
    }
    return result;
}

// arrange words to indices
std::unordered_map<std::string, int> string_list_to_map(const std::vector<std::string> &strings) {
    std::unordered_map<std::string, int> map;
    int index = 0;
    for (const std::string &string : strings) {
        if (map.find(string) == map.end()) {
            index += 1;
            map[string] = index;
        }
    }
    return map;
}

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