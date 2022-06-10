#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void merge_sort_res(int *array, int left, int right);
void merge(int *array, int left, int middle, int right);
void print_array(const int *array, size_t size);

#endif /* SORT_H_ */
