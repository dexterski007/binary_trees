#include "binary_trees.h"

/**
 * binary_tree_leaves - count leaves
 *
 * @tree: pointer to root
 *
 * Return: 0 or count
 */


size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t	left_l, right_l;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_l = binary_tree_leaves(tree->left);
	right_l = binary_tree_leaves(tree->right);

	return (left_l + right_l);
}
