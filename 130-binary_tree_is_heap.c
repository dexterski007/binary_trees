#include "binary_trees.h"

int binary_complete(const binary_tree_t *root, int ind, int count);
size_t binary_tree_size(const binary_tree_t *tree);
int binary_complete_tree(const binary_tree_t *tree);
int bigger_parent(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - is heap maxx
 *
 * @tree: pointer to root
 *
 * Return: 1 or 0
 */


int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_complete_tree(tree))
		return (0);

	return (bigger_parent(tree->left) && bigger_parent(tree->right));
}

/**
 * bigger_parent - check if parent is bigger
 *
 * @tree: pointer to root
 *
 * Return: 1 or 0
 */

int bigger_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (bigger_parent(tree->left) && bigger_parent(tree->right));
}


/**
 * binary_complete_tree - prepare for complete check
 *
 * @tree: pointer to root
 *
 * Return: 1 or 0
 */


int binary_complete_tree(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	count = binary_tree_size(tree);

	return (binary_complete(tree, 0, count));
}


/**
 * binary_complete - bst checker
 *
 * @root: pointer to root
 * @ind: index
 * @count: count of nodes
 *
 * Return: 1 or 0
 */

int binary_complete(const binary_tree_t *root, int ind, int count)

{
	if (root == NULL)
		return (1);

	if (ind >= count)
		return (0);

	return (binary_complete(root->left, 2 * ind + 1, count) &&
			binary_complete(root->right, 2 * ind + 2, count));
}

/**
 * binary_tree_size - size of tree
 *
 * @tree: pointer to root
 *
 * Return: 0 or size
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	if (tree != NULL)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	return (size);
}

