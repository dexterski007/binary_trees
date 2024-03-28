#include "binary_trees.h"

avl_t *avl_helper(avl_t **tree, avl_t *parent, avl_t **new_node, int value);


/**
 * avl_insert - avl insert
 *
 * @tree: pointer to root
 * @value: value to insert
 *
 * Return: Null or pointer to node
 */


avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	avl_helper(tree, *tree, &new_node, value);
	return (new_node);
}

/**
 * avl_helper - avl helper
 *
 * @tree: pointer to root
 * @parent: value to parent
 * @new_node: new node
 * @value: value
 *
 * Return: Null or pointer to new root
 */


avl_t *avl_helper(avl_t **tree, avl_t *parent, avl_t **new_node, int value)
{
	int index;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_helper(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_helper(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	index = binary_tree_balance(*tree);
	if (index > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (index < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (index > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (index < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);

}

