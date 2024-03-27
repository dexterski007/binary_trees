#include "binary_trees.h"

/**
 * binary_tree_uncle - find uncle of node
 *
 * @node: pointer to node
 *
 * Return: pointer to sibling
 */


binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
		node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent != NULL)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		if (node->parent->parent->right == node->parent)
			return (node->parent->parent->left);
	}

	return (NULL);
}
