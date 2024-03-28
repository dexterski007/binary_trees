#include "binary_trees.h"


/**
 * bst_insert - bst insert
 *
 * @tree: pointer to root
 * @value: value to insert
 *
 * Return: Null or pointer to node
 */


bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *current, *parent;

	if (tree == NULL)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	}

	current = *tree;
	while (current != NULL)
	{
		parent = current;
		if (value == current->n)
		{
			free(new);
			return (NULL);
		}
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}
	if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;
	new->parent = parent;
	return (new);
}
