// Boston KJ
// Hangman Struct
// Contains the whole game

#include "Letter.h"
#include <stdio.h>

struct Hangman
{
    int length;
    int numGuesses;
    int score;
    Letter *word;
    Letter *guessed;
};

void printString(Hangman *game); // print the word, underscores if the letters have not yet been guessed
Hangman *initializeHangman(int length, char *clue); // create hangman game with included word
Hangman *initializeHangmanFile(FILE *input, int chosenWord); // create hangman game using an input file
void findLetter(Hangman *game, char guess); // check if included letter is part of the word, reduce score if not, mark letter as guessed
bool gameOver(Hangman *game); // return if gameWon is true OR if score reaches 0
bool gameWon(Hangman *game); // return true if all letters part of the word are guessed
void freeHangman(Hangman *game); // free memory associated with game