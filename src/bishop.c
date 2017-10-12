#include <stdlib.h>
#include <stdio.h>

extern int checkPosition(int row, int col, int b[][8]);

int bishop(int pos[], int board[][8]) {
    /*[col][row][col][row]*/
    /*pos[] contains current positions and new positions [0][1]=current [2][3] = new*/
    int i, j;
    
    if (pos[3] > pos[1] && pos[2] > pos[0]) {
        /*move south east*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        printf("South east: (%d,%d) -> (%d,%d)\n",pos[0],pos[1],pos[2],pos[3]);
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            printf("Bishop error: Not a move of bishop\n");
            return 0;
        }
        i = pos[1];
        for (j = pos[0] + 1; j < pos[2]; j++) {
            i++;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Bishop error: South east: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] > pos[1] && pos[2] < pos[0]) {
        /*move south west*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        printf("South west: (%d,%d) -> (%d,%d)\n",pos[0],pos[1],pos[2],pos[3]);
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            printf("Bishop error: Not a move of bishop\n");
            return 0;
        }
        i = pos[1];
        for (j = pos[0] - 1; j > pos[2]; j--) {
            i++;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Bishop error: South west: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] < pos[1] && pos[2] < pos[0]) {
        /*move north west*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        printf("North west: (%d,%d) -> (%d,%d)\n",pos[0],pos[1],pos[2],pos[3]);
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            printf("Bishop error: Not a move of bishop\n");
            return 0;
        }
        i = pos[1];
        for (j = pos[0] - 1; j > pos[2]; j--) {
            --i;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                // Bc1-a6 get here
                printf("Bishop error: North west: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] < pos[1] && pos[2] > pos[0]) {
        /*move north east*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        printf("North east: (%d,%d) -> (%d,%d)\n",pos[0],pos[1],pos[2],pos[3]);
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            printf("Bishop error: Not a move of bishop\n");
            return 0;
        }
        i = pos[1];
        for (j = pos[0] + 1; j < pos[2]; j++) {
            --i;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Bishop error: North east: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else {
        /*illegal move*/
        return 0;
    }
}