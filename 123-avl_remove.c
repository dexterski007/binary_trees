#include "binary_trees.h"

bst_t *min_val(bst_t *tree);
bst_t *bst_rm_inf(bst_t *root, int value);
int ind_del(bst_t *tree);
int son(bst_t *node);
void balance_checker(avl_t **tree);

/**
 * avl_remove - remove bst
 *
 * @root: pointer to root
 * @value: value to search
 *
 * Return: pointer to new root
 */


avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tree;

	tree = (avl_t *) bst_rm_inf((bst_t *) root, value);

	if (tree == NULL)
		return (NULL);
	balance_checker(&tree);

	return (tree);
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
 * @value: value to delete
 *
 * Return: pointer to root
 */

bst_t *bst_rm_inf(bst_t *root, int value)
{
	int ind = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_rm_inf(root->left, value);
	else if (value > root->n)
		bst_rm_inf(root->right, value);
	else if (root->n == value)
	{
		ind = ind_del(root);
		if (ind != 0)
			bst_rm_inf(root->right, ind);
	}
	else
		return (NULL);
	return (root);
}

/**
 * ind_del - delete on children
 *
 * @tree: pointer to root
 *
 * Return: 0 if no child or int
 */

int ind_del(bst_t *tree)
{
	int check = 0;

	if (tree->left == NULL && tree->right == NULL)
	{
		if (tree->parent->right == tree)
			tree->parent->right = NULL;
		else
			tree->parent->left = NULL;
		free(tree);
		return (0);
	}
	else if ((tree->left == NULL && tree->right != NULL) ||
				(tree->right == NULL && tree->left != NULL))
	{
		if (tree->left == NULL)
		{
			if (tree->parent->right == tree)
				tree->parent->right = tree->right;
			else
				tree->parent->left = tree->right;
			tree->right->parent = tree->parent;
		}
		if (tree->right == NULL)
		{
			if (tree->parent->right == tree)
				tree->parent->right = tree->left;
			else
				tree->parent->left = tree->left;
			tree->left->parent = tree->parent;
		}
		free(tree);
		return (0);
	}
	else
	{
		check = son(tree->right);
		tree->n = check;
		return (check);
	}
}

/**
 * son - get the worthy one
 *
 * @node: pointer to node
 *
 * Return: min val
 */

int son(bst_t *node)
{
	int num = 0;

	if (node == NULL)
		return (0);
	num = son(node->left);
	if (num == 0)
		return (node->n);
	return (num);
}

/**
 * balance_checker - rebalance tree
 *
 * @tree: pointer to tree
 */

void balance_checker(avl_t **tree)
{
	int index;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance_checker(&(*tree)->left);
	balance_checker(&(*tree)->right);
	index = binary_tree_balance((const binary_tree_t *)*tree);
	if (index > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (index < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
