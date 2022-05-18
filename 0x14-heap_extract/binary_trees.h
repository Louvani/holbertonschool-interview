#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};


typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);
size_t binary_tree_height(const heap_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
void _preorder(heap_t *tree, heap_t **node, size_t height);
void heapify(heap_t *root);

#endif /* _BINARY_TREES_H_ */
