#include "binary_trees.h"

bst_t *min_val(bst_t *node);
bst_t *bst_rm_inf(bst_t *root, bst_t *node, int value);
bst_t *bst_del(bst_t *root, bst_t *node);

/**
 * bst_remove - remove bst
 *
 * @root: pointer to root
 * @value: value to search
 *
 * Return: pointer to new root
 */


bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_rm_inf(root, root, value));
}

/**
 * min_val - find node with min val
 * @tree: pointer to tree
 *
 * Return: pointer to node with min val
 */

bst_t *min_val(bst_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}


/**
 * bst_rm_inf - recursive delete node
 * @root: pointer to root
 * @node: pointer to node
 * @value: value to delete
 *
 * Return: pointer to root
 */

bst_t *bst_rm_inf(bst_t *root, bst_t *node, int value)
{
	if (node == NULL)
		return (NULL);

	if (node->n == value)
		return (bst_del(root, node));
	if (node->n > value)
		return (bst_rm_inf(root, node->left, value));
	return (bst_rm_inf(root, node->right, value));
}

/**
 * bst_del - delete node
 * @root: pointer to root
 * @node: pointer to node
 *
 * Return: pointer to root
 */

bst_t *bst_del(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *son = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		if (parent == NULL)
			return (node->right);
		else
			return (root);
	}
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		if (parent == NULL)
			return (node->left);
		else
			return (root);
	}

	son = min_val(node->right);
	node->n = son->n;

	return (bst_del(root, son));
}
