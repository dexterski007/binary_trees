#include "binary_trees.h"


/**
 * array_to_avl - convert avl from array
 *
 * @array: array of value
 * @size: size of array
 *
 * Return: pointer to root
 */


avl_t *array_to_avl(int *array, size_t size)
{
	size_t n = 0, s = 0;
	bst_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (n = 0; n < size; n++)
	{
		for (s = 0; s < n; s++)
		{
			if (array[s] == array[n])
				break;
		}
		if (s == n)
		{
			if (avl_insert(&tree, array[n]) == NULL)
			return (NULL);
		}
	}

	return (tree);
}
