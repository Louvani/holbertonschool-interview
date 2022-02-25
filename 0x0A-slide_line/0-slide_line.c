#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array
 * @size: size of array
 * @direction: direction to slide
 *
 * Return: 1 for success, 0 for failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_RIGHT && direction != SLIDE_LEFT) || !line)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		left(line, size);
		return (move_left(line, size));
	}
	else
	{
		right(line, size);
		return (move_right(line, size));
	}
}

/**
 * left - merge numbers to left
 * @line: array
 * @size: size
 */
void left(int *line, size_t size)
{
	int idx = 0, next = 1;

	while (next < (int) size)
	{
		if (line[idx] == 0)
		{
			idx++;
			next++;
			continue;
		}
		while (next < (int) size && line[next] == 0)
			next++;
		if (next >= (int) size)
			break;
		if (line[idx] == line[next])
		{
			line[idx] *= 2;
			line[next] = 0;
			idx = next + 1;
			next = idx + 1;
		}
		else
		{
			idx = next;
			next = idx + 1;
		}
	}
}

/**
 * right - merge numbers to right
 * @size: size
 * @line: array
 */
void right(int *line, size_t size)
{
	int idx, next;

	for (idx = (int) size - 1, next = idx - 1; next >= 0;)
	{
		if (!line[idx])
		{
			idx--;
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0)
			next--;
		if (next < 0)
			break;
		if (line[idx] == line[next])
		{
			line[idx] *= 2;
			line[next] = 0;
			idx = next - 1;
			next = idx - 1;
		}
		else
		{
			idx = next;
			next--;
		}
	}
}
/**
 * move_right - move numbers to right
 * @size: size
 * @line: array
 *
 * Return: 1
 */
int move_right(int *line, int size)
{
	int current, next;

	for (current = size - 1, next = current - 1; current >= 0; current--)
	{
		if (line[current])
		{
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0)
			next--;
		if (next < 0)
			return (1);
		line[current] = line[next];
		if (current != next)
			line[next] = 0;
	}
	return (1);
}

/**
 * move_left - move numbers to left
 * @size: size
 * @line: array
 *
 * Return: 1
 */
int move_left(int *line, int size)
{
	int current, next;

	for (current = 0, next = 1; current < size; current++)
	{
		if (line[current])
		{
			next++;
			continue;
		}
		while (next < size && line[next] == 0)
			next++;
		if (next >= size)
			return (1);
		line[current] = line[next];
		if (current != next)
			line[next] = 0;
	}
	return (1);
}
