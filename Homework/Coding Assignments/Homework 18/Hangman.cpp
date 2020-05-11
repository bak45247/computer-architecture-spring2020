// Boston KJ
// Hangman implementation

#include "Hangman.h"
#include <stdlib.h>
#include <stdio.h>

void printString(Hangman *game)
{
    for(int i = 0; i < game->length; i++)
    {
        if(game->word[i].beenGuessed == true)
            printf("%c ", game->word[i].character);
        else
            printf("_ ");
    }
}

Hangman *initializeHangman(int length, char *clue);
void findLetter(Hangman *game, char guess)
{
    bool included = false; // This will change to true if the letter is part of the word

    for(int i = 0; i < game->length; i++)
    {
        if(game->word[i].character == guess)
        {
            game->word[i].beenGuessed == true;
            included = true;
        }
    }

    for(int i =0; i < game->numGuesses; i++)
    {
        if(game->guessed[i].character == guess)
        {
            return;
        }
    }

    game->numGuesses += 1;
    game->guessed[game->numGuesses].character = guess;
    game->guessed[game->numGuesses].beenGuessed = true;

    if(included == false) // if we get here and this is false, the letter was NOT part of the word and the score is reduced by 1 point
        game->score -= 1;

    return;
}

bool gameOver(Hangman *game);
bool gameWin(Hangman *game);
void freeHangman(Hangman *game);