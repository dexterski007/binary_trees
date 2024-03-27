#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate right
 *
 * @tree: pointer to root
 *
 * Return: pointer to new tree
 */


binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newtree, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	newtree = tree->left;
	temp = newtree->right;

	newtree->right = tree;
	tree->left = temp;

	if (temp != NULL)
		temp->parent = tree;
	newtree->parent = tree->parent;
	tree->parent = newtree;

	return (newtree);
}
