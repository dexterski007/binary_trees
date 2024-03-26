#include "binary_trees.h"

/**
 * binary_tree_inorder - inorder tree
 *
 * @tree: pointer to root
 * @func: pointer to function
 */


void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (func == NULL)
		return;

	binary_tree_inorder(tree->left, func);

	func(tree->n);

	binary_tree_inorder(tree->right, func);
}
