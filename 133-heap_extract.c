#include "binary_trees.h"

heap_t *mx(heap_t *root);
void extractor(heap_t *root);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);


/**
 * heap_extract - extract heap
 *
 * @root: root pointer
 *
 * Return: extracetd value
 */


int heap_extract(heap_t **root)
{
	int value;

	if (*root == NULL)
		return (0);

	value = (*root)->n;

	if ((*root)->left == NULL)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}

	extractor(*root);

	return (value);
}

/**
 * extractor - extractor heap
 *
 * @root: root pointer
 */

void extractor(heap_t *root)
{
	heap_t *childm, *rightm = NULL;

	if (root->left == NULL)
		return;

	childm = mx((root)->left);
	if (root->right)
		rightm = mx(root->right);
	if (rightm && rightm->n > childm->n)
		childm = rightm;
	root->n = childm->n;
	if (childm->left == NULL)
	{
		if (childm->parent && childm->parent->left == childm)
			childm->parent->left = NULL;
		if (childm->parent && childm->parent->right == childm)
			childm->parent->right = NULL;
		free(childm);
	}
	else
		extractor(childm);

}

/**
 * mx - maximum node
 *
 * @root: root pointer
 *
 * Return: node with max val
 */


heap_t *mx(heap_t *root)
{
	heap_t *max, *maxl, *maxr;

	if (root->left == NULL)
		return (root);
	maxl = mx(root->left);
	if (maxl->n > root->n)
		max = maxl;
	else
		max = root;
	if (root->right != NULL)
	{
		maxr = mx(root->right);
		if (maxr->n > max->n)
			max = maxr;
		else
			max = root;
	}
	return (max);
}

/**
 * binary_tree_node - insert node
 *
 * @parent: parent of the node
 * @value: value of the node
 *
 * Return: pointer to the node
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *child_node;

	child_node = malloc(sizeof(binary_tree_t));
	if (child_node == NULL)
		return (NULL);

	child_node->n = value;
	child_node->parent = parent;
	child_node->left = NULL;
	child_node->right = NULL;

	return (child_node);
}
