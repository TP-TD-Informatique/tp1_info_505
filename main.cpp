#include <iostream>

#include "questions.hpp"

int main() {
    std::vector<std::string> keys = std::vector<std::string>();
    std::cout << "Quels mots cherchez-vous ?" << std::endl;
    std::string key;
    do {
        std::cout << "\t";
        std::getline(std::cin, key);
        if (!key.empty()) keys.emplace_back(key);
    } while (!key.empty());

    std::string str;
    std::cout << "Dans quelle phrase ?" << std::endl;
    do {
        std::cout << "\t";
        std::getline(std::cin, key);
        if (!key.empty()) str = key;
    } while (key.empty());

    std::map<std::string, std::vector<int> *> *result = search(str, keys);

    std::cout << std::endl << "Résultats :" << std::endl;
    for (auto &it : *result) {
        std::cout << it.first << " : (";
        std::cout << it.second->size() << ") ";
        for (int &it2 : *it.second) std::cout << it2 << " ";
        std::cout << std::endl;
    }

    return 0;
}
