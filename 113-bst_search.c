#include "binary_trees.h"


/**
 * bst_search - search bst
 *
 * @tree: pointer to root
 * @value: value to search
 *
 * Return: pointer to node
 */


bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *) tree);
		else if (tree->n > value)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}
