#pragma once
#include <iostream>
#include <string>

class Game
{
    int correct;
    int lifes;
    std::string guessingWord;

    public:
    std::string guess;
    std::string level;
    std::string correctLetters;

    void gameplay();
    void lookingFor();
    void check();

    Game();
    ~Game();
};

void Game::gameplay()
{
    std::cout << "LIFES:" << lifes << '\t' << "CORRECT LETTERS:" << correctLetters << std::endl;
    std::cout << "\n" << level << "\n" << "Enter an a letter you think is in a word: ";
    std::cin >> guess;
    
    lookingFor();
}

void Game::lookingFor()
{
    for (int i = 0; i < guessingWord.size(); i++)
    {
        auto j = guessingWord.find(guess[i]);
        if (j == std::string::npos)
        {
            continue;
        }
        else
        {
            
            if(j == i)
            {
                level[i] = guess[i];
                guess.replace(i, 1, "+");
                guessingWord.replace(i, 1, "-");
                correct += 1;
                correctLetters.clear();
            }
            else
            {
                correctLetters += guess[i];
            }
        }
           
    }

    check();
}

void Game::check()
{
    system("cls");
    lifes--;

    if (correct == guessingWord.size())
    {
        std::cout << "The word was " << level << "\n";
        std::cout << "You won!";
    }
    else if (lifes == 0)
    {
        std::cout << "You lost :(";
    }
    else gameplay();
}

Game::Game()
{
    std::cout << "Enter an a word you want to guess: ";
    std::cin >> guessingWord;
    level = std::string (guessingWord.size(), '-');
    lifes = 6;
    correct = 0;
    system("cls");
}

Game::~Game()
{
}
