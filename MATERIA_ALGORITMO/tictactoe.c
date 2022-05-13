#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSLOTS 9

typedef struct {
    int player;
} Mark;

typedef struct {
    int currentPlayer;
    Mark *marks[MAXSLOTS];
} GameTable;

int winConditions[][8] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        
        {0, 4, 8},
        {2, 4, 6}
};

int win = 0;
bool tie = false;
    
Mark *salloc(void);
void printTable();
bool checkWin();
int getValidInput(GameTable *table);

char* messages[3] = {
    "Empate!", "Jogador 1 venceu!", "Jogador 2 venceu!"
};

int main()
{
    /*
    0 1 2
    3 4 5 
    6 7 8
    */
    GameTable *table;
    table = (GameTable *) malloc(sizeof(GameTable));
    
    for (int i = 0; i < MAXSLOTS; i++) {
        table->marks[i] = salloc();
        table->marks[i]->player = -1;
    }
    
    table->currentPlayer = 0;
    while (!win) {
        printTable(table);
        printf("Jogador nº%d:", (table->currentPlayer + 1));
        int i = getValidInput(table);
        table->marks[i]->player = table->currentPlayer;
        
        if (checkWin(table)) {
            char* msg = messages[win];
            printTable(table);
            printf("%s",msg);
            break;
        }
        
        table->currentPlayer = !table->currentPlayer;
    }
    
    for (int i = 0; i < MAXSLOTS; i++) {
        free(table->marks[i]);
    }
    //free(table->marks); 
    free(table);
    return 0;
}

Mark *salloc(void)
{
    return (Mark *) malloc(sizeof(Mark));
}

void printTable(GameTable *table)
{
    for (int i = 0; i < MAXSLOTS; i++) {
        if (i % 3 == 0) {
            printf("\n");
        }
        char c = (i + 1) + '0';
        //printf("%d", table->marks[i]->player);
        switch (table->marks[i]->player) {
            case 0:
                c = 'X';
                break;
            case 1:
                c = 'O';
                break;
        } 
        printf("%c ", c);
    }
    printf("\n");
}

bool checkWin(GameTable *table) 
{
    bool isTie = true;
    for (int i = 0; i < 8; i++) {
        int idx1 = winConditions[i][0];
        int idx2 = winConditions[i][1];
        int idx3 = winConditions[i][2];
        //printf("%d", idx1);        
        int markPlayer1 = table->marks[idx1]->player;
        int markPlayer2 = table->marks[idx2]->player;
        int markPlayer3 = table->marks[idx3]->player;
        
        //printf("%d", markPlayer1);
        
        if (markPlayer1 == -1 || markPlayer2 == -1 || markPlayer3 == -1) {
            if (isTie) {
                isTie = false;
            }
            continue;
        }
        
        if (markPlayer1 == markPlayer2 && markPlayer2 == markPlayer3) {
            win = markPlayer1 + 1;
            return true;
        }
    }
    if (isTie) {
        win = 0;
        tie = true;
    }
    return isTie;
}

int getValidInput(GameTable *table)
{
    int input;
    bool valid = false;
    do {
        scanf("%d", &input);
        if (input > 9 || input < 1) {
            continue;
        }
        input--;
        if (table->marks[input]->player == -1) {
            valid = true;
        }
    } while (!valid);
    return input;
}
