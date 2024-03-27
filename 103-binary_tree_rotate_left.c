#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate left
 *
 * @tree: pointer to root
 *
 * Return: pointer to new tree
 */


binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newtree, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	newtree = tree->right;
	temp = newtree->left;

	newtree->left = tree;
	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;
	newtree->parent = tree->parent;
	tree->parent = newtree;

	return (newtree);
}
