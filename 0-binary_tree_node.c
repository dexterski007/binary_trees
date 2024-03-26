#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *child_node;

	child_node = malloc(sizeof(binary_tree_t));
	if (child_node == NULL)
		return NULL;

	child_node->n = value;
	child_node->parent = parent;
	child_node->left = NULL;
	child_node->right = NULL;

	return (child_node);
}
