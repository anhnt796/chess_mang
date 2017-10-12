#include <stdlib.h>
#include <stdio.h>

extern int checkPosition(int row, int col, int b[][8]);

int queen(int pos[], int board[][8]) {
    /*[col][row][col][row]*/
    /*pos[] contains current positions and new positions [0][1]=current [2][3] = new*/
    int i, j;
    if (pos[3] > pos[1] && pos[2] == pos[0]) {
        /*move south*/
        for (i = pos[1] + 1; i < pos[3]; ++i) {
            if (checkPosition(i, pos[0], board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: South: piece (%c%c) on the move\n", pos[0]+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] == pos[1] && pos[2] < pos[0]) {
        /*move west*/
        for (i = pos[0] - 1; i > pos[2]; --i) {
            if (checkPosition(pos[1], i, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: West: piece (%c%c) on the move\n", i+97, 8-pos[1]+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] < pos[1] && pos[2] == pos[0]) {
        /*move north*/
        for (i = pos[1] - 1; i > pos[3]; --i) {
            if (checkPosition(i, pos[0], board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: North: piece (%c%c) on the move\n", pos[0]+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] == pos[1] && pos[2] > pos[0]) {
        /*move east*/
        for (i = pos[0] + 1; i < pos[2]; ++i) {
            if (checkPosition(pos[1], i, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: East: piece (%c%c) on the move\n", i+97, 8-pos[1]+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] > pos[1] && pos[2] > pos[0]) {
        /*move south east*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            return 0;
        }
        i = pos[1];
        for (j = pos[0] + 1; j < pos[2]; ++j) {
            i++;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: South east: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] > pos[1] && pos[2] < pos[0]) {
        /*move south west*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            return 0;
        }
        i = pos[1];
        for (j = pos[0] - 1; j > pos[2]; --j) {
            ++i;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: South west: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] < pos[1] && pos[2] < pos[0]) {
        /*move north west*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            return 0;
        }
        i = pos[1];
        for (j = pos[0] - 1; j > pos[2]; --j) {
            --i;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: North west: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else if (pos[3] < pos[1] && pos[2] > pos[0]) {
        /*move north east*/
        /*if move is not horizontal, return 0*/
        /*change in x-axis must equal change in y-axis*/
        if (!(abs(pos[0] - pos[2]) == abs(pos[1] - pos[3]))) {
            return 0;
        }
        i = pos[1];
        for (j = pos[0] + 1; j < pos[2]; ++j) {
            --i;
            if (checkPosition(i, j, board)) {
                /*if piece at intermediate position move is illegal*/
                printf("Queen error: North east: piece (%c%c) on the move\n", j+97, 8-i+48);
                return 0;
            }
        }
        /*reached new position*/
        return 1;
    } else {
        /*illegal move*/
        printf("Illegal move");
        return 0;
    }
}