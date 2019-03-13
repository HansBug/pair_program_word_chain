#define DLL_EXPORTS // put this before #include "core.h"

#include "core.h"
#include <iostream>
#include "functions.h"
#include "string_process.h"

EXPORT int TEST_LIB_PLUS(int a, int b) {
    return a + b;
}

EXPORT int gen_chain_word(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop) {
    std::vector<std::string> word_list = char_array_ptr_to_vector(words, len);

    int ret = words_circle_check(word_list);
    if (ret && !enable_loop) {
        return ret;
    }

    if (!enable_loop) {
        std::vector<std::string> *chain_ptr_without_circle;
        ret = get_chain_with_word(word_list, chain_ptr_without_circle, head, tail);

        if (ret) {
            return ret;
        } else {
            if (chain_ptr_without_circle != nullptr) {
                std::vector<std::string> chain = *chain_ptr_without_circle;
                auto length = chain.size();
                vector_to_char_array_ptr(chain, result);
                return length;
            } else {
                return NO_SOLUTION_FOUND;
            }
        }
    } else {
        // TODO : COMPLETE IT
        return NOT_IMPLEMENT;
    }
}

EXPORT int gen_chain_char(char *words[], int len, char *result[],
                          char head, char tail, bool enable_loop) {
    std::vector<std::string> word_list = char_array_ptr_to_vector(words, len);

    int ret = words_circle_check(word_list);
    if (ret && !enable_loop) {
        return ret;
    }

    if (!enable_loop) {
        std::vector<std::string> *chain_ptr_without_circle;
        ret = get_chain_with_char(word_list, chain_ptr_without_circle, head, tail);

        if (ret) {
            return ret;
        } else {
            if (chain_ptr_without_circle != nullptr) {
                std::vector<std::string> chain = *chain_ptr_without_circle;
                auto length = chain.size();
                vector_to_char_array_ptr(chain, result);
                return length;
            } else {
                return NO_SOLUTION_FOUND;
            }
        }
    } else {
        // TODO : COMPLETE IT
        return NOT_IMPLEMENT;
    }
}