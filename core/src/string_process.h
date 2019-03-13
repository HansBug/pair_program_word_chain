//
// Created by admin on 2019/3/11.
//

#ifndef CORE_UTILS_H
#define CORE_UTILS_H

#include <unordered_map>
#include <vector>
#include <string>

bool is_downcase(const char &ch);

char downcase(const char &ch);

// turn string to downcase
std::string downcase(const std::string &string);

bool is_upcase(const char &ch);

char upcase(const char &ch);

// turn string to upcase
std::string upcase(const std::string &string);

// switch all the words to downcase words
std::vector<std::string> strings_to_downcase(const std::vector<std::string> &strings);

// arrange words to indices
std::unordered_map<std::string, int> string_list_to_map(const std::vector<std::string> &strings);

// turn word array ptr to string vector
std::vector<std::string> char_array_ptr_to_vector(char *words[], int len);

// turn string vector to char array ptr
int vector_to_char_array_ptr(const std::vector<std::string> &words, char *result[]);

#endif //CORE_UTILS_H
