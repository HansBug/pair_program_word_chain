
#include "core.h"
#include <iostream>
#include "functions.h"
#include "string_process.h"

int gen_chain_word(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop) {
    std::vector<std::string> word_list = char_array_ptr_to_vector(words, len);
    int ret;
    std::vector<std::string> *chain_ptr = nullptr;

    if (!enable_loop) {
        ret = get_chain_with_word(word_list, chain_ptr, head, tail);
    } else {
        ret = get_chain_with_word_allow_same(word_list, chain_ptr, head, tail);
    }

    if (ret) {
        return ret;
    } else {
        if (chain_ptr != nullptr) {
            std::vector<std::string> chain = *chain_ptr;
            auto length = chain.size();
            vector_to_char_array_ptr(chain, result);
            return length;
        } else {
            return NO_SOLUTION_FOUND;
        }
    }
}

int gen_chain_char(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop) {
    std::vector<std::string> word_list = char_array_ptr_to_vector(words, len);
    int ret;
    std::vector<std::string> *chain_ptr = nullptr;

    if (!enable_loop) {
        ret = get_chain_with_char(word_list, chain_ptr, head, tail);
    } else {
        ret = get_chain_with_char_allow_same(word_list, chain_ptr, head, tail);
    }

    if (ret) {
        return ret;
    } else {
        if (chain_ptr != nullptr) {
            std::vector<std::string> chain = *chain_ptr;
            auto length = chain.size();
            vector_to_char_array_ptr(chain, result);
            return length;
        } else {
            return NO_SOLUTION_FOUND;
        }
    }
}