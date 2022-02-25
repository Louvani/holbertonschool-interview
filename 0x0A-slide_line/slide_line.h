#ifndef SLIDE_LINE
#define SLIDE_LINE

#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int slide_line(int *line, size_t size, int direction);

int move_right(int *line, int size);
int move_left(int *line, int size);
void right(int *line, size_t size);
void left(int *line, size_t size);

#endif