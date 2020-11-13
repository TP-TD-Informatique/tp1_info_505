#include "questions.hpp"

int search(std::string search, std::string str) {
    // Pour chaque caractères dans str
    for (int i = 0; i < str.size() - search.size(); ++i) {
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
            // Si on a trouvé on renvoie la position de la première occurrence du mot
            if (find) return i;
        }
    }
    // Si on a pas trouvé, on renvoie -1
    return -1;
}

std::map<std::string, std::vector<int> *> *search(const std::string &str, std::vector<std::string> &keywords) {
    auto *result = new std::map<std::string, std::vector<int> *>(); // vector contenant les résultats

    auto *compts = new std::vector<int>(keywords.size(), 0); // L'automate

    for (int i = 0; i < str.size(); i++) { // Pour chaque caractères
        for (int j = 0; j < keywords.size(); ++j) { // Pour chaque mots cherchés
            if (keywords[j][(*compts)[j]] != str[i]) (*compts)[j] = 0; // Si le caractère est différent
            if (keywords[j][(*compts)[j]] == str[i]) (*compts)[j]++; // Si le caractère est égal

            if ((*compts)[j] == keywords[j].size()) { // Si le mot est trouvé
                // On rajoute l'occurence dans le tableau de résultat
                auto it = result->find(keywords[j]);
                if (it == result->end()) { // Si le mot n'a encore jamais été trouvé
                    auto *vector = new std::vector<int>();
                    vector->push_back(i - keywords[j].size() + 1);
                    result->emplace(keywords[j], vector);
                } else { // Si on a déjà trouvé le mot au moins une fois
                    std::vector<int> *vector = it->second;
                    vector->push_back(i - keywords[j].size() + 1);
                    result->emplace(keywords[j], vector);
                }
            }
        }
    }

    for (auto &it : keywords) { // Pour chaque mots cherchés
        if (result->find(it) == result->end()) { // Si le mot n'a jamais été trouvé
            auto *i = new std::vector<int>();
            result->emplace(it, i); // On rajoute un tableau vide comme résultat
        }
    }

    return result;
}