/////////////////////////////////
// Play Hangman Drive
// HW 19 Main
///////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "Hangman.h"

int main(int argc, char *argv[])
{
        // Homework 18 beginning, creating the hangman game with an included word
        // char clue[5] = {'Q', 'U', 'E', 'U', 'E'};
        // Hangman *h = initializeHangman(5, clue);

        int numGames;
        printf("How many games would you like to play?\n");
        scanf("%d", &numGames);

        int round = 1;
        while(!round == numGames) // loops through rounds until its equal to the number of games wanted to be played
        {
                int numWords = atoi(argv[1]);
                FILE *input = fopen(argv[2], "r");

                printf("================= ROUND %d =================\n", round);
                printf("Choose a number between 1 and %d\n", numWords); // user chooses the number of the word
                int chosenWord;
                scanf("%d", &chosenWord); // scanning for the int to be entered

                if(chosenWord <= numWords) // sanity checking, ensures the chosen word will always be within the given values
                {
                        Hangman *h = initializeHangmanFile(input, chosenWord); // making the hangman game using the input file and chosen number

                        while (!gameOver(h))
                        {
                                printString(h);
                                char guess = 'A';
                                printf("Enter your guess: ");
                                scanf(" %c", &guess);
                                findLetter(h, guess);
                        }
                        if (gameWon(h))
                        {
                                printString(h);
                                printf("You won with score: %d\n", h->score);
                        }
                        else
                                printf("You lost\n");
                        freeHangman(h);
                        h = NULL;
                        round += 1; // increment round counter on complete game
                        fclose(input);
                }
                else
                {
                        printf("Please choose a number inside of the given range\n");
                }
                
        }
        return 0;
}
