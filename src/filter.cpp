#include "filter.hpp"

using std::string;
using std::vector;

// TODO: remove tokenize, unnecessary and can error checking can be implemented into get_next_guess()
std::vector<result> tokenize(std::string input){
    std::vector<result> res;
    for (char c : input){
        switch (c) {
            case 'x':
                res.push_back(result::EXACT);
                break;
            case 'i':
                res.push_back(result::INCLUDED);
                break;
            case 'n':
                res.push_back(result::NONE);
                break;
            default:
                res.clear();
                return res;
        }
    }
    return res;
}

bool includes_char(std::string word, char character) {
    for (char c : word) {
        if (c == character) {
            return true;
        }
    }
    return false;
}

vector<string> read_file(string path) {
    vector<string> words;
    std::ifstream file(path);
    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    }
    return words;
}

vector<string> filter_definite_char(vector<string> currentList, unsigned long index, char character){
    vector<string> newList;
    for (string word : currentList) {
        if (word[index] == character) {
            newList.push_back(word);
        }
    }
    return newList;
}

vector<string> filter_indefinite_char(vector<string> currentList, char character){
    vector<string> newList;
    for (string word : currentList) {
        if (includes_char(word, character)) {
            newList.push_back(word);
        }
    }
    return newList;
}

vector<string> filter_definite_not_char(vector<string> currentList, char character){
    vector<string> newList;
    for (string word : currentList) {
        bool containsChar = false;
        for (char c : word){
            if (c == character) {
                containsChar = true;
            }
        }
        if (!containsChar){
            newList.push_back(word);
        }
    }
    return newList;
}
