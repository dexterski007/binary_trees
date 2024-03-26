#include "binary_trees.h"

/**
 * binary_tree_depth - depth of tree
 *
 * @tree: pointer to root
 *
 * Return: 0 or height
 */


size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}	


	return (depth);
}
