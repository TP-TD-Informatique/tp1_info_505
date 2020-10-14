#include <iostream>

#include "questions.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    //std::cout << search("World", "Hello, World!") << std::endl;

    std::vector<std::string> keys = std::vector<std::string>();
    keys.emplace_back("ni");
    keys.emplace_back("rein");
    keys.emplace_back("rene");
    keys.emplace_back("irene");
    std::map<std::string, std::vector<int> *> *result = search("annie n'honnit ni nina ni irene", keys);

    for (auto &it : *result) {
        std::cout << it.first << " : (";
        std::cout << it.second->size() << ") ";
        for (int &it2 : *it.second) std::cout << it2 << " ";
        std::cout << std::endl;
    }

    return 0;
}
