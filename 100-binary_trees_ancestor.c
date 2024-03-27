#include "binary_trees.h"

/**
 * binary_trees_ancestor - find lowest ancestor
 *
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to lowest ancestor
 */


binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first->parent == second->parent)
		return (binary_trees_ancestor(first->parent, second->parent));
	else
		return (binary_trees_ancestor(first, second->parent));
}
