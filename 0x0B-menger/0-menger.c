#include "menger.h"

/**
 * menger - function to print a menfet
 *
 * @level: the level of menger sponge
 */
void menger(int level)
{
	int num, row, col, drow, dcol, f;

	num = (int)pow(3, level);
	for (col = 0; col < num; col++)
	{
		for (row = 0; row < num; row++)
		{
			dcol = col;
			drow = row;
			f = 0;
			while (dcol && drow)
			{
				if (drow % 3 == 1 && dcol % 3 == 1)
				{
					printf(" ");
					f = 1;
					break;
				}
				drow = drow / 3;
				dcol = dcol / 3;
			}
			if (!f)
			{
				printf("#");
			}
		}
		printf("\n");
	}
}
