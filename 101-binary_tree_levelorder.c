#include "binary_trees.h"

/**
 * enqueue - Add an element to the end of the queue
 * @queue: A pointer to the queue where the element should be added
 * @address: A pointer to the data (in this case, a memory address) to be added
 * Return: (void)
 */
void enqueue(Queue *queue, const void *address)
{
	Node *new;

	if (!queue)
		return;
	new = malloc(sizeof(Node));
	if (new)
	{
		new->btree_node = address;
		new->next = NULL;
		if (!queue->front) /* if queue is empty */
			queue->front = queue->rear = new;
		else
		{
			queue->rear->next = new;
			queue->rear = new;
		}
	}
}

/**
 * dequeue - Remove and return the front element from the queue.
 * @queue: A pointer to the queue from which an element should be removed
 * Return: the memory address that is stored in the queue
 */
const void *dequeue(Queue *queue)
{
	Node *tmp;
	const void *address;

	if (!queue || !queue->front)
		return (NULL);
	tmp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL) /* if no element been in queue */
		queue->rear = NULL;
	address = tmp->btree_node;
	free(tmp);
	return (address);
}

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: (void)
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Queue *queue;
	const binary_tree_t *btree_node;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(Queue));
	if (queue)
	{
		queue->front = queue->rear = NULL;
		enqueue(queue, tree);
		while (queue->front)
		{
			/* dequeue and get the btree-node address */
			btree_node = dequeue(queue);

			func(btree_node->n);
			if (btree_node->left)
				enqueue(queue, btree_node->left);
			if (btree_node->right)
				enqueue(queue, btree_node->right);
		}
		free(queue);
	}
}
