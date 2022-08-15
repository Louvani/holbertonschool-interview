#include "binary_trees.h"

/**
 * sorted_array_to_avl - function  that builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (!array ? NULL : insert_AVL_node(NULL, array, 0, (int)size - 1));
}

/**
 * new_node - function that creates a new node
 * @parent: pointer to the parent
 * @value: value of the node
 * Return: pointer to the created node
 */
avl_t *new_node(avl_t *parent, size_t value)
{
	avl_t *node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * insert_AVL_node - function to inserta new node
 * @parent: pointer to the parent
 * @array: array
 * @start: start index
 * @end: end index
 * Return: pointer to the created node
 */
avl_t *insert_AVL_node(avl_t *parent, int *array, int start, int end)
{
	size_t midle;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);
	midle = (start + end) / 2;
	root = new_node(parent, array[midle]);
	if (!root)
		return (NULL);
	root->left = insert_AVL_node(root, array, start, midle - 1);
	root->right = insert_AVL_node(root, array, midle + 1, end);
	return (root);
}
