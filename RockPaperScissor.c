#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateBotMove();
int getPlayerMove();
void determineOutcome(int playerMove, int botMove);

int main() {

    srand(time(NULL));  // Seed random number generator

    printf("=== ROCK PAPER SCISSOR ===\n");

    int playerMove = getPlayerMove();
    int botMove = generateBotMove();

    switch(playerMove) {
        case 1:
            printf("You picked ROCK!\n");
            break;
        case 2:
            printf("You picked PAPER!\n");
            break;
        case 3:
            printf("You picked SCISSOR!\n");
            break;
    }

    switch(botMove) {
        case 1:
            printf("Bot picked ROCK!\n");
            break;
        case 2:
            printf("Bot picked PAPER!\n");
            break;
        case 3:
            printf("Bot picked SCISSOR!\n");
            break;
    }

    determineOutcome(playerMove, botMove);

    return 0;
}

int generateBotMove() {
    return (rand() % 3) + 1;  // Random number between 1 and 3
}

int getPlayerMove() {
    int selection = 0;

    do {
        printf("Make your selection:\n");
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSOR\n");
        printf("Enter number (1-3): ");
        scanf("%d", &selection);
    } while (selection < 1 || selection > 3);

    return selection;
}

void determineOutcome(int playerMove, int botMove) {
    if (playerMove == botMove) {
        printf("Result: DRAW!\n");
    }
    else if ((playerMove == 1 && botMove == 3) ||
             (playerMove == 2 && botMove == 1) ||
             (playerMove == 3 && botMove == 2)) {
        printf("Result: VICTORY!\n");
    }
    else {
        printf("Result: DEFEAT!\n");
    }
}
