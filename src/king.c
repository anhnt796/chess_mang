#include <stdio.h>
extern int squareUnderAttack(int colPos, int rowPos, int player, int board[][8]);

int king(int pos[], int player, int board[][8]) {
    /*[col][row][col][row]*/
    /*pos[] contains current positions and new positions [0][1]=current [2][3] = new*/
    printf("%d %d %d %d\n", pos[0], pos[1], pos[2], pos[3]);
    if (player) {
        /* player is black */
        if (pos[3] == pos[1] + 1 && pos[2] == pos[0]) {
            /*move south*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] && pos[2] == pos[0] - 1) {
            /*move west*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] - 1 && pos[2] == pos[0]) {
            /*move north*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] && pos[2] == pos[0] + 1) {
            /*move east*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] + 1 && pos[2] == pos[0] + 1) {
            /*move south east*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] + 1 && pos[2] == pos[0] - 1) {
            /*move south west*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] - 1 && pos[2] == pos[0] - 1) {
            /*move north west*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] - 1 && pos[2] == pos[0] + 1) {
            /*move north east*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else {
            /*illegal move*/
            return 0;
        }
    } else {
        /* player is white */
        if (pos[3] == pos[1] + 1 && pos[2] == pos[0]) {
            /*move south*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] && pos[2] == pos[0] - 1) {
            /*move west*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] - 1 && pos[2] == pos[0]) {
            /*move north*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] && pos[2] == pos[0] + 1) {
            /*move east*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] + 1 && pos[2] == pos[0] + 1) {
            /*move south east*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] + 1 && pos[2] == pos[0] - 1) {
            /*move south west*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] - 1 && pos[2] == pos[0] - 1) {
            /*move north west*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else if (pos[3] == pos[1] - 1 && pos[2] == pos[0] + 1) {
            /*move north east*/
            if (squareUnderAttack(pos[2], pos[3], player, board)) {
                return 0;
            }
            return 1;
        } else {
            /*illegal move*/
            return 0;
        }
    }
}
