// Boston KJ
// Hangman Struct
// Contains the whole game

#include "Letter.h"

struct Hangman
{
    int length;
    Letter *word;
    Letter *alphabet;
}

void printString(Hangman *game); // print the word, underscores if the letters have not yet been guessed
Hangman *initializeHangman(int length, char *clue); // create hangman game
void findLetter(Hangman *game, char guess); // check if included letter is part of the word, reduce score if not, mark letter as guessed
bool gameOver(Hangman *game); // return if gameWin is true OR if score reaches 0
bool gameWin(Hangman *game); // return true if all letters part of the word are guessed
void freeHangman(Hangman *game); // free memory associated with game