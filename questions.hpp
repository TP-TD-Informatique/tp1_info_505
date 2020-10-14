#ifndef TP1_QUESTIONS_HPP
#define TP1_QUESTIONS_HPP

#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <sstream>

// Question 1
// Cherche search dans str
int search(std::string search, std::string str);

// Question 2
std::map<std::string, std::vector<int> *> *search(const std::string &str, std::vector<std::string> &keyword);

#endif //TP1_QUESTIONS_HPP
