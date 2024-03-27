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
	binary_tree_t *parent_s, *parent_f;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	parent_s = second->parent;
	parent_f = first->parent;

	if (parent_s == first || parent_f == NULL ||
		(parent_f->parent == NULL && parent_s != NULL))
		return (binary_trees_ancestor(first, parent_s));
	if (parent_f == second || parent_s == NULL ||
		(parent_s->parent == NULL && parent_f != NULL))
		return (binary_trees_ancestor(second, parent_f));

	return (binary_trees_ancestor(parent_s, parent_f));
}
