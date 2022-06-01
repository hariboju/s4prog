#include "play_guess_the_number.hpp"
#include "get_input.hpp"
#include "random.hpp"

/*int get_int_from_user()
{
    // TODO ;) Use std::cin to get an int, and then return it
    int user_int;
    std::cin >> user_int;
    return user_int;
}*/

void play_guess_the_number()
{
    // TODO
    int recup_random = rand(0, 100);
    std::cout << recup_random;
    bool finished = false;

    while (!finished) {
        std::cout << "Choose a number between 0 and 100: ";

        const int user_integer = get_input<int>(); // Ask for a number
        if (user_integer == recup_random) {
            std::cout << "congrate";
            finished = true;
        }
        else if (user_integer < recup_random) {
            std::cout << "Greater" << std::endl;
        }
        else if (user_integer > recup_random) {
            std::cout << "Smaller" << std::endl;
        }
        // If it is the correct one then set finished to true
        // Else give a hint to the user ("Greater" or "Smaller")
    }
}