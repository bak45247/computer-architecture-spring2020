// Boston KJ
// Hangman implementation

#include "Hangman.h"

void printString(Hangman *game)
{
    for(int i = 0; i < length; i++)
    {
        if(word[i]->guessed = True)
            printf("%c ", word[i]->character);
        else
            printf("_ ");
    }
}

Hangman *initializeHangman(int length, char *clue);
void findLetter(Hangman *game, char guess);
bool gameOver(Hangman *game);
bool gameWin(Hangman *game);
void freeHangman(Hangman *game);