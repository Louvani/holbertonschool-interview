#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdlib.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void auxsort(int *array, int size, int lsd);
void csort2(int *array, int **buff, int size, int lsd);

#endif /* SORT_H */
