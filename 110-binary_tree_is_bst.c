#include "binary_trees.h"

int bst_checker(const binary_tree_t *tree, const binary_tree_t *min,
				const binary_tree_t *max);

/**
 * binary_tree_is_bst - is bst
 *
 * @tree: pointer to root
 *
 * Return: 1 or 0
 */


int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return bst_checker(tree, NULL, NULL);
}

/**
 * bst_checker - bst checker
 *
 * @tree: pointer to root
 * @min: min value of subtree
 * @max: max value of subtree
 *
 * Return: 1 or 0
 */

int bst_checker(const binary_tree_t *tree, const binary_tree_t *min,
				const binary_tree_t *max)

{
	if (tree == NULL)
		return (1);
	if (((min != NULL) && (tree->n <= min->n)) || ((max != NULL) &&
		(tree->n >= max->n)))
		return (0);

	return (bst_checker(tree->left, min, tree) && bst_checker(tree->right, tree, max));
}
