#include "binary_trees.h"

const binary_tree_t *dequeue(queue_t **queue);
void enqueue(queue_t **queue, const binary_tree_t *node);

/**
 * binary_tree_levelorder - find lowest ancestor
 *
 * @tree: pointer to root
 * @func: function
 */


void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *current;

	if (func == NULL || tree == NULL)
		return;
	enqueue(&queue, tree);

	while (queue != NULL)
	{
		current = dequeue(&queue);

		func(current->n);

		if (current->left != NULL)
			enqueue(&queue, current->left);
		if (current->right != NULL)
			enqueue(&queue, current->right);
	}

}

/**
 * enqueue - enqueue node to queue
 *
 * @queue: queue
 * @node: node
 */


void enqueue(queue_t **queue, const binary_tree_t *node)
{
	queue_t *current, *new = malloc(sizeof(queue_t));

	if (new == NULL)
		return;

	new->node = node;
	new->next = NULL;

	if (*queue == NULL)
		*queue = new;
	else
	{
		current = *queue;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

/**
 * dequeue - remove from queue
 *
 * @queue: double pointer to queue
 *
 * Return: node
 */


const binary_tree_t *dequeue(queue_t **queue)
{
	queue_t *temp;
	const binary_tree_t *node;

	if (*queue == NULL)
		return (NULL);

	temp = *queue;
	node = temp->node;
	*queue = (*queue)->next;
	free(temp);

	return (node);

}
