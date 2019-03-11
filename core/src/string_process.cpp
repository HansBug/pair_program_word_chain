//
// Created by admin on 2019/3/11.
//

#include "string_process.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// turn string to downcase
std::string downcase(const std::string &string) {
    std::string result(string);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
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

// check if there are word circle(s)
bool has_word_circle(const std::vector<std::string> &strings) {
    std::unordered_set<char> head_chars;
    std::unordered_set<char> tail_chars;
    for (const std::string &string : strings) {
        if (string.length() <= 0) {
            continue;
        }
        char head = string.at(0);
        head_chars.insert(head);

        char tail = string.at(string.length() - 1);
        tail_chars.insert(tail);
    }

    for (const char &ch : head_chars) {
        if (tail_chars.find(ch) != tail_chars.end()) {
            return true;
        }
    }
    return false;
}