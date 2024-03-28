#include "binary_trees.h"

int height(const binary_tree_t *tree);
int check_bst(const binary_tree_t *tree, int min, int max);

/**
 * height - calculate height
 *
 * @tree: pointer to tree
 *
 * Return: height of tree
 */

int height(const binary_tree_t *tree)
{
	size_t lef = 0, rig = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		lef = (1 + height(tree->left));
	else
		lef = 1;

	if (tree->right != NULL)
		rig = (1 + height(tree->right));
	else
		rig = 1;

	if (lef > rig)
		return (lef);
	else
		return (rig);
}


/**
 * check_bst - check if is bst
 *
 * @tree: pointer to tree
 * @min: min value
 * @max: max value
 *
 * Return: 1 or 0
 */


int check_bst(const binary_tree_t *tree, int min, int max)
{
	size_t num;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	num = abs((height(tree->left)) - (height(tree->right)));
	if (num > 1)
		return (0);

	return (check_bst(tree->left, min, tree->n - 1)
			&& check_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - avl checker
 *
 * @tree: pointer to root
 *
 * Return: 1 or 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)

{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}
