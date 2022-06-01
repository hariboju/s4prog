#include "hangman.hpp"
#include <stdlib.h>
#include <string.h>
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include "random.hpp"

// choose a word in the list, don't use word with the same lettre twice or more
const std::string pick_random_word()
{
    static constexpr std::array words = {
        "trouve",
        "imac",
        "janvier",
        "opengl",
    };

    return words[rand<size_t>(0, words.size() - 1)];
}

// message send to the user to tell him his life
void show_life(int number_life)
{
    if (number_life == 1) {
        std::cout << number_life << " life left!" << std::endl;
    }
    else {
        std::cout << number_life << " lives left!" << std::endl;
    }
}

// asking a lettre to the user
char get_letter()
{
    char letter;
    std::cin >> letter;
    return letter;
}

bool word_contains(char letter, std::string word)
{
    if (word.find(letter) != std::string::npos) // check until the end of our word
        return true;
    else
        return false;
}

void reduce_life(int& number_life) // remove a life to the player
{
    number_life--;
}

void word_and_lettre_left(std::string word, std::vector<bool> letters_guessed)
{
    size_t i                   = 0;
    int    numbre_of_caractere = word.size(); // counting the number of caractere in the word
    std::cout << "The word is " << numbre_of_caractere << " lettre long, guess it: " << std::endl;
    while (i < word.size()) {
        if (letters_guessed[i])
            std::cout << word[i];
        else
            std::cout << "_";
        i++;
    }
    std::cout << std::endl;
}

void lettre_guessed(char guessed_letter, std::vector<bool>& letters_guessed,
                    std::string word) // showing lettre founded on the word
{
    size_t i = 0;
    while (i < word.size()) {
        if (word[i] == guessed_letter)
            letters_guessed[i] = true;
        i++;
    }
}

bool still_alive(int number_life) // check if player has still lives left
{
    if (number_life > 0)
        return true;
    else
        return false;
}

bool player_has_won(std::vector<bool> letters_guessed) // check if player has won
{
    bool   winner = false;
    size_t i      = 0;
    while (i < letters_guessed.size()) {
        if (letters_guessed[i]) {
            winner = true;
        }
        else {
            winner = false;
        }
        i++;
    }
    return winner;
}

void final_message(int number_life, std::vector<bool> letters_guessed,
                   std::string played_word) // final message send to the user
{
    if (player_has_won(letters_guessed)) {
        std::cout << "\nCongrate, you have fiunded the word " << played_word << std::endl;
    }
    if (!still_alive(number_life)) {
        std::cout << "\nNo life left, you loose, do you like to know it (type 1 for yes, 2 for no)? " << std::endl;
        int yn; // let the player choose if he wants to know the word or not
        std::cin >> yn;
        if (yn == 1) {
            std::cout << "\nThe word was " << played_word << std::endl;
        }
        else {
            std::cout << "Cheh";
        }
    }
}

void hangman()
{
    std::string       played_word = pick_random_word();
    std::vector<bool> letters_guessed;
    for (size_t i = 0; i < played_word.size(); i++) {
        letters_guessed.push_back(false);
    }
    int number_life = 2; // choose the number of life at the beggening of the game
    std::cout << "Lets play Hangman together\n"
              << std::endl;
    while (still_alive(number_life) && !player_has_won(letters_guessed)) {
        show_life(number_life);
        word_and_lettre_left(played_word, letters_guessed);
        const auto test_letter = get_letter();
        if (word_contains(test_letter, played_word)) {
            lettre_guessed(test_letter, letters_guessed, played_word);
            std::cout << "You have founded a lettre ! lets try to find another one.\n";
        }
        else {
            std::cout << "this one is flase, try again...\n";
            reduce_life(number_life);
        }
    }
    final_message(number_life, letters_guessed, played_word);
}