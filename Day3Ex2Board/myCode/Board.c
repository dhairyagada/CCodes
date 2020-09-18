#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

char* allocateMemory(int size)
{
	char *myAddress = 0;
	//Allocate Memory
	myAddress = (char*) malloc(size * sizeof(char));
	return myAddress;
}

errorCode_t assignSymbol(board_t *const me, int row, int col, char *symbol)
{
	if (row > me->rows || col > me->cols)
	{
		return FAIL;
	}

	(me->charArray)[(row - 1) * (me->cols) + col - 1] = *symbol;
	return SUCCESS;
}
void initializeCharArray(board_t *const me, char *initialSymbol)
{

	int rows = me->rows;
	int cols = me->cols;

	int counter = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			(me->charArray)[counter] = *initialSymbol;
			counter = counter + 1;
		}

	}

}
void create_board(board_t *const me, int rows, int cols)
{

	me->rows = rows;
	me->cols = cols;
	me->charArray = allocateMemory(rows * cols);

	initializeCharArray(me, ".");
}

void print_board(board_t const *const board)
{
	int rows = board->rows;
	int cols = board->cols;
	int counter = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{

			printf("%c ", board->charArray[counter]);
			counter = counter + 1;
		}
		printf("\n");
	}
}

