#include "solver.hpp"

#include <random>
#include <ctime>

using std::vector;
using std::string;

string currentGuess;
vector<string> currentList;

void start_game(){
    currentList = read_file("words.txt");
    fmt::print("Guess: {}\n", get_next_guess());
}

std::string get_next_guess(){
    srand(time(NULL));
    currentGuess = currentList[rand() % currentList.size()];
    return currentGuess;
}

std::string get_next_guess(std::vector<result> res){
    // TODO: change from random to sorting list by amount of data stored
    // Might as well describe future implementation of this while it's fresh in my mind.
    // Determine which words have the most data stored (e.g. narrows down the possibilities the most)
    // Most likely to be done with huffman codes (https://www.youtube.com/watch?v=B3y0RsVCyrw) 
    // Note that I despise information theory, and this may be entirely incorrect.
    for (unsigned long i = 0; i < res.size(); ++i){
        switch (res[i]){
            case result::EXACT:
                currentList = filter_definite_char(currentList, i, currentGuess[i]);
                break;
            case result::INCLUDED:
                currentList = filter_indefinite_char(currentList, currentGuess[i]);
                break;
            case result::NONE:
                currentList = filter_definite_not_char(currentList, currentGuess[i]);
                break;
        }
    }
    srand(time(NULL));
    assert(currentList.size() > 0 && "No possible words left.");
    currentGuess = currentList[rand() % currentList.size()];
    return currentGuess;
}
