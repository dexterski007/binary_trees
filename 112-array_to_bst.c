#include "binary_trees.h"


/**
 * array_to_bst - convert bst from array
 *
 * @array: array of value
 * @size: size of array
 *
 * Return: pointer to root
 */


bst_t *array_to_bst(int *array, size_t size)
{
	size_t n = 0;
	bst_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (n = 0; n < size; n++)
	{
		if (bst_insert(&tree, array[n]) == NULL)
			return (NULL);
	}

	return (tree);
}
