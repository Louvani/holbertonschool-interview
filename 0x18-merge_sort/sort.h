#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int start, int mid, int end);
void sort(int *arr, int *l, int *r, int start, int mid, int end);
void merge_sort(int *array, size_t size);
void divide_array(int *array, int start, int end);
void print_array(const int *array, size_t size);

#endif /* SORT_H_ */
