#include "binary_trees.h"

size_t binary_size(const binary_tree_t *tree);

/**
 * heap_insert - heap insert
 *
 * @root: pointer to root
 * @value: value to insert
 *
 * Return: Null or pointer to node
 */


heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *tree, *rev;
	int size, niv, temp, leaf, bit, sub;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	tree = *root;
	size = binary_size(tree);
	leaf = size;
	for (niv = 0, sub = 1; leaf >= sub; sub *= 2, niv++)
		leaf -= sub;
	for (bit = 1 << (niv - 1); bit != 1; bit >>= 1)
	{
		if (leaf & bit)
			tree = tree->right;
		else
			tree = tree->left;
	}
	new_node = binary_tree_node(tree, value);
	if (leaf & 1)
		tree->right = new_node;
	else
		tree->left = new_node;
	rev = new_node;
	for (; rev->parent && (rev->n > rev->parent->n); rev = rev->parent)
	{
		temp = rev->n;
		rev->n = rev->parent->n;
		rev->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * binary_size - binary_size helper
 *
 * @tree: pointer to root
 *
 * Return: size of tree
 */


size_t binary_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_size(tree->left) + binary_size(tree->right) + 1);
}

