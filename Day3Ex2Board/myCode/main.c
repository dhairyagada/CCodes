#include <stdio.h>
#include <stdlib.h>

#include "Board.h"

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);

	board_t board =	{};

	int rows, cols;
	printf("The starting point of a board game\n");
	printf("Enter No. of Rows:");
	scanf("%d", &rows);
	printf("Enter No. of Cols:");
	scanf("%d", &cols);
	create_board(&board, rows, cols);

	printf("Allocated board of dimension x=%d, y=%d at address %p\n", rows,
			cols, board.charArray);
	print_board(&board);

	while (1)
	{
		int x, y;
		char symbol;

		printf("Please enter a position (x,y) and a character (0 to end):\n");
		scanf("%d", &x);
		scanf("%d", &y);
		scanf(" %c", &symbol);

		errorCode_t code = assignSymbol(&board, x, y, &symbol);
		if (code == SUCCESS)
		{
			print_board(&board);
		}
		else
		{
			printf("Enter Positions within Range\n");
		}

	};

}

