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