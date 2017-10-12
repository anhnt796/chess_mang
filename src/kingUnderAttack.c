/* This function checks if the king is currently under attack
 * If the king is under attack, returns 1, else returns 0
 * Specially returns 2 if double-check.
 * Test later.
 */
#include "pieceConst.h"

extern int rook(int pos[], int board[][8]);

extern int knight(int pos[], int board[][8]);

extern int bishop(int pos[], int board[][8]);

extern int queen(int pos[], int board[][8]);

extern int king(int pos[], int player, int board[][8]);

extern int pawn(int pos[], int player, int board[][8]);

extern int makemove(int pos[], int board[][8]);

int kingUnderAttack(int player, int board[][8]) {
	
	int i, j, king, colKing, rowKing;
	king = player ? bKing : wKing;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (board[i][j] == king) {
				colKing = j;
				rowKing = i;
			}
		}
	}
	
	if (squareUnderAttack(colKing, rowKing, player, board)) {
		return 1;
	} else {
		return 0;
	}
}
