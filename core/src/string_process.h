//
// Created by admin on 2019/3/11.
//

#ifndef CORE_UTILS_H
#define CORE_UTILS_H

#include <unordered_map>
#include <vector>
#include <string>

// turn string to downcase
std::string downcase(const std::string &string);

// turn string to upcase
std::string upcase(const std::string &string);

// switch all the words to downcase words
std::vector<std::string> strings_to_downcase(const std::vector<std::string> &strings);

// arrange words to indices
std::unordered_map<std::string, int> string_list_to_map(const std::vector<std::string> &strings);

// check if there are word circle(s)
bool has_word_circle(const std::vector<std::string> &strings);

#endif //CORE_UTILS_H
