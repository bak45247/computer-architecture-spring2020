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

    printf("\nLetters Guessed: ");
    for(int i = 0; i < game->numGuesses; i++)
    {
        printf("%c ", game->guessed[i].character);
    }

    printf("\nCurrent Score: %d\n", game->score);
}

Hangman *initializeHangman(int length, char *clue)
{
    // creating the hangman object and setting all variables to initial states
    Hangman *game = (Hangman*)malloc(sizeof(Hangman));
    game->length = length;
    game->numGuesses = 0;
    game->score = 10;
    game->word = (Letter*)malloc(sizeof(Letter) * length);
    game->guessed = (Letter*)malloc(sizeof(Letter) * 26);

    for(int i = 0; i < length; i++) // copying the clue array to the word array
    {
        game->word[i].character = clue[i];
        game->word[i].beenGuessed = false;
    }

    return game;
}

Hangman *initializeHangmanFile(FILE *input, int chosenWord) // creating the hangman game with a file input
{
    // Finding the word in the file and setting corresponding variables
    int length = 0; // length of the word chosen
    char word[40]; // the chosen word (shouldn't be more than 40 characters)

    // probably not the best way to do this, but we read each line and leave the loop when we reach the desired word
    for(int i = 1; i <= chosenWord; i++)
    {
        fscanf(input, "%d", &length);
        fscanf(input, "%s", word);
    }

    // creating the hangman object and setting all variables to initial states
    Hangman *game = (Hangman*)malloc(sizeof(Hangman));
    game->length = length;
    game->numGuesses = 0;
    game->score = 10;
    game->word = (Letter*)malloc(sizeof(Letter) * length);
    game->guessed = (Letter*)malloc(sizeof(Letter) * 26);

    for(int i = 0; i < length; i++) // copying the files word array to the games word array
    {
        game->word[i].character = word[i];
        game->word[i].beenGuessed = false;
    }

    return game;
}

void findLetter(Hangman *game, char guess)
{
    bool included = false; // This will change to true if the letter is part of the word

    for(int i = 0; i < game->length; i++)
    {
        if(game->word[i].character == guess)
        {
            game->word[i].beenGuessed = true;
            included = true;
        }
    }

    for(int i =0; i < game->numGuesses; i++)
    {
        if(game->guessed[i].character == guess) // if the guess matches anything, don't do anything
        {
            return;
        }
    }

    if(!included)
    {
        game->score -= 1;
    }
    game->guessed[game->numGuesses].character = guess; // place the new letter at this point in the array
    game->guessed[game->numGuesses].beenGuessed = true; // set this to true as it has been guessed
    game->numGuesses += 1; // increment number of guesses

    return;
}

bool gameOver(Hangman *game)
{
    if(gameWon(game) || game->score == 0) // we either won, or the score is zero
        return true;

    return false; // if it gets here, neither conditions are met
}

bool gameWon(Hangman *game)
{
    for(int i = 0; i < game->length; i++)
    {
        if(!game->word[i].beenGuessed) // if any letter hasn't been guessed, the player hasn't won
            return false;
    }

    return true; // if it gets here, every letter has been guessed and the player won
}

void freeHangman(Hangman *game)
{
    free(game->guessed);
    free(game->word);
    free(game);
}