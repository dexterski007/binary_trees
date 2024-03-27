#include "binary_trees.h"

/**
 * binary_tree_is_perfect - measures perfectness
 *
 * @tree: pointer to root
 *
 * Return: 0 or 1
 */


int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, max = 0, num = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	max = (1 << (height + 1)) - 1;
	num = binary_tree_size(tree);

	return (num == max);
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


/**
 * binary_tree_height - height of tree
 *
 * @tree: pointer to root
 *
 * Return: 0 or height
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_h = binary_tree_height(tree->left) + 1;
	else
		left_h = 0;
	if (tree->right != NULL)
		right_h = binary_tree_height(tree->right) + 1;
	else
		right_h = 0;

	if (left_h > right_h)
		return (left_h);
	else
		return (right_h);
}

