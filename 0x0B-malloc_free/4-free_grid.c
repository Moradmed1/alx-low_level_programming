#include "main.h"
#include <stdlib.h>

/**
 * free_grid - free 2d array
 * @grid: 2d grid of memories
 * @height: height dimention of grid
 * Description: frees memory of grid
 * Return: nothing
 */

void free_grid(int **grid, int height)
{
	int i = 0;

	for (; i < height; i++)
		free(grid[i]);
	free(grid);
}
