#include "binary_trees.h"

avl_t *sorted_recursion(avl_t *parent, int *array, int begin, int end);

/**
 * sorted_array_to_avl - convert avl from sorted array
 *
 * @array: array of value
 * @size: size of array
 *
 * Return: pointer to root
 */


avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_recursion(NULL, array, 0, ((int)size - 1)));
}

/**
 * sorted_recursion - recursion while avl
 *
 * @array: array of value
 * @begin: beginning of array
 * @end: end of array
 *
 * Return: pointer to root
 */


avl_t *sorted_recursion(avl_t *parent, int *array, int begin, int end)
{
	binary_tree_t *new;
	int mid = 0;
	avl_t *root;

	if (begin > end)
		return (NULL);

	mid = (begin + end) / 2;

	new = binary_tree_node((binary_tree_t *)parent, array[mid]);
	if (new == NULL)
		return (NULL);
	root = (avl_t *)new;
	root->left = sorted_recursion(root, array, begin, mid - 1);
	root->right = sorted_recursion(root, array, mid + 1, end);

	return (root);
}
