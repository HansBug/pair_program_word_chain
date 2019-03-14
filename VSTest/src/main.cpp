#define NO_DLL

#include <string>
#include <iostream>
#include "string_process.h"
#include "core.h"

int main() {
    auto words = std::vector<std::string>{
            "algebra",
            "pseudopseudohypoparathyroidism",
            "trick",
            "moon",
            "leaf",
            "apple",
            "zoo",
            "under",
            "fox",
            "elephant",
            "dog"
    };

    char *s[100];
    auto length = vector_to_char_array_ptr(words, s);

    char *res[100];
    int ret = gen_chain_word(s, length, res, NO_START_CHAR, NO_END_CHAR, false);

    if (ret >= 0) {
        auto result_length = (unsigned) ret;
        std::vector<std::string> list = char_array_ptr_to_vector(res, result_length);
        for (const std::string &word : list) {
            std::cout << word << " ---> ";
        }
    } else {
        std::cout << "error : " << ret << std::endl;
    }
    return 0;

}