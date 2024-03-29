#include "binary_trees.h"


size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - convert heap to array
 *
 * @heap: pointer to heap
 * @size: adress with size of the array
 *
 * Return: array
 */


int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int num, i = 0;
	size_t h_size;

	if (heap == NULL)
		return (NULL);

	h_size = binary_tree_size(heap);
	*size = h_size;
	array = malloc(h_size * sizeof(int));
	if (array == NULL)
		return (NULL);

	while (heap)
	{
		num = heap_extract(&heap);
		array[i] = num;
		i++;
	}
	return (array);

}


/**
 * binary_tree_size - size of tree
 *
 * @tree: pointer to root
 *
 * Return: 0 or size
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	if (tree != NULL)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	return (size);
}

