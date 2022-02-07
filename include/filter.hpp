#pragma once

#include "common.hpp"
#include <fstream>

enum result {
    NONE,
    INCLUDED,
    EXACT
};

std::vector<result> tokenize(std::string input);
std::vector<std::string> read_file(std::string path);
std::vector<std::string> filter_definite_char(std::vector<std::string> currentList, unsigned long index, char character);
std::vector<std::string> filter_indefinite_char(std::vector<std::string> currentList, char character);
std::vector<std::string> filter_definite_not_char(std::vector<std::string> currentList, char character);
