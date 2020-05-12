/////////////////////////////////
// Play Hangman Drive
// HW 18 Shell
///////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "Hangman.h"

int main()
{
        char clue[5] = {'Q', 'U', 'E', 'U', 'E'};
        Hangman *h = initializeHangman(5, clue);

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
                printf("You won with score: %d\n", h->score);
        }
        else
                printf("You lost\n");
        freeHangman(h);
        h = NULL;
        return 0;
}
