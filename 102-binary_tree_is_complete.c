#include "binary_trees.h"

int binary_tree_check_complete(const binary_tree_t *tree, size_t index,
								size_t count);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - check if complete
 *
 * @tree: pointer to root
 *
 * Return 0 or 1
 */


int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_check_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_check_complete - check complete
 *
 * @queue: queue
 * @node: node
 */


int binary_tree_check_complete(const binary_tree_t *tree, size_t index,
								size_t count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);
	return (binary_tree_check_complete(tree->left, 2 * index + 1, count) &&
			binary_tree_check_complete(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_size - size of tree
 *
 * @tree: pointer to root
 *
 * Return: 0 or size
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	if (tree != NULL)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	return (size);
}

