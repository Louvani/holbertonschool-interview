#include "binary_trees.h"


/**
 * heap_extract -function docs
 * @root: root
 * Return: a value
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, binary_tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Is a pointer to the root node of the tree to traverse.
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);

	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}

/**
* binary_tree_size - This function measures
* the size of a binary tree.
* @tree: is a pointer to the node to measure the depth
* Return: 0 if tree is NULL,
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * _preorder - function docs
 * @tree: tree
 * @node: node
 * @height: height
 *
 * Return: void
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - function docs
 * @root: root
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

