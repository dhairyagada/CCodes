/*
 * Board.h
 *
 *  Created on: 16-Sep-2020
 *      Author: dhair
 */

#ifndef BOARD_H_
#define BOARD_H_

typedef struct
{
	int rows;
	int cols;
	char *charArray;

} board_t;

typedef enum {
	SUCCESS=0,
	FAIL=1
}errorCode_t;

char* allocateMemory(int size);
errorCode_t assignSymbol(board_t *const me, int row, int col, char *symbol);
void initializeCharArray(board_t *const me, char *initialSymbol);
void create_board(board_t *const me, int rows, int cols);
void print_board(board_t const * const board);

#endif /* BOARD_H_ */
