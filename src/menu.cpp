#include <stdlib.h>
#include <string.h>
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include "hangman.hpp"
#include "play_guess_the_number.hpp"
#include "random.hpp"

void showMenu()
{
    bool quit = false;
    while (quit == false) {
        std::cout << "what do you want to do ? " << std::endl;
        std::cout << "Type 1 to play Guess the number. " << std::endl;
        std::cout << "Type 2 to Hangman. " << std::endl;
        std::cout << "Type 0 to quit. " << std::endl;
        int number;
        std::cin >> number;
        if (number == 1) {
            play_guess_the_number();
        }
        else if (number == 2) {
            hangman();
        }
        else {
            quit = true;
        }
    }
}