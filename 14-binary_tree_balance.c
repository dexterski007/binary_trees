#include "binary_trees.h"

/**
 * binary_tree_balance - measures balance
 *
 * @tree: pointer to root
 *
 * Return: 0 or balance
 */


int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
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
		left_h = 1;
	if (tree->right != NULL)
		right_h = binary_tree_height(tree->right) + 1;
	else
		right_h = 1;

	if (left_h > right_h)
		return (left_h);
	else
		return (right_h);
}
