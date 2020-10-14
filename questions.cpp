#include "questions.hpp"

int search(std::string search, std::string str) {
    // Pour chaque caractères dans str
    for (int i = 0; i < str.size(); ++i) {
        // Si le caractère est égale au premier caractère de search
        // et que search rentre dans str
        if (str[i] == search[0] && search.size() + i <= str.size()) {
            bool find = true;
            // Pour chaque caractères de search
            for (int j = 0; j < search.size(); ++j) {
                // Si le caractère est différent, on n'a pas trouvé et on quitte la boucle
                if (search[j] != str[i + j]) {
                    find = false;
                    break;
                }
            }
            // Si on a trouvé on renvoie vraie
            if (find) return i;
        }
    }
    // Si on a pas trouvé, on renvoie faux
    return -1;
}

std::map<std::string, std::vector<int> *> *search(const std::string &str, std::vector<std::string> &keyword) {
    auto *result = new std::map<std::string, std::vector<int> *>();

    auto *compts = new std::vector<int>(keyword.size());
    for (int i = 0; i < keyword.size(); ++i) compts->push_back(0);

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < keyword.size(); ++j) {
            if (keyword[j][(*compts)[j]] != str[i]) (*compts)[j] = 0;
            if (keyword[j][(*compts)[j]] == str[i]) (*compts)[j]++;

            if ((*compts)[j] == keyword[j].size()) {
                auto it = result->find(keyword[j]);
                if (it == result->end()) {
                    auto *vector = new std::vector<int>();
                    vector->push_back(i - keyword[j].size() + 1);
                    result->emplace(keyword[j], vector);
                } else {
                    std::vector<int> *vector = it->second;
                    vector->push_back(i - keyword[j].size() + 1);
                    result->emplace(keyword[j], vector);
                }
            }
        }
    }

    auto it = keyword.begin();
    for (; it != keyword.end(); it++) {
        if (result->find(*it) == result->end()) {
            auto *i = new std::vector<int>();
            result->emplace(*it, i);
        }
    }
    return result;
}