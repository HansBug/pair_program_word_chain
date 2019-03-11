#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

int main() {
    std::vector<std::string> strings{"2", "3", "as", "2", "df", "3"};
    auto map = string_list_to_map(strings);
    for (const std::string &string : strings) {
        std::cout << string << " " << map[string] << " " << upcase(string) << " " << downcase(string) << std::endl;
    }
}