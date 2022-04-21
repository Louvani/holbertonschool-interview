#ifndef SORT_H
#define sort_h


#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heapify(int *array, size_t size);

#endif /* LISTS_H */