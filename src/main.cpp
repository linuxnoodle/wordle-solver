#include <iostream>

#include "common.hpp"
#include "solver.hpp"
#include "filter.hpp"

int main(int argc, char *argv[]){
    std::string welcoming_message =
    "Respond with 5 letters (x for exact [meaning green], i for included [meaning yellow], and n for none [meaning grey]).\n"
    "\tExample: xinni\n"
    "Have fun!\n\n";
    fmt::print(fmt::emphasis::bold | fg(fmt::color::green), "{}", welcoming_message);

    std::string result;
    start_game();
    for (int i = 0; i < 5; ++i){
        fmt::print(fg(fmt::color::yellow), ">  ");
        
        std::cin >> result; 
        
        auto res = tokenize(result);
        if (res.empty()){
            --i;
            fmt::print(fg(fmt::color::red), "Please enter a valid reponse.\n");
        } else {
            fmt::print("Guess: {}\n", get_next_guess(res));
        }
    }
    
    return 0;
}
