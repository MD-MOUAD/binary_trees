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
void free2(Queue *queue)
{
	Node *tmp;

	if (!queue)
		return;
	while (queue->front)
	{
		tmp = queue->front;
		queue->front = queue->front->next;
		free(tmp);
	}
	free(queue);
}
void in_order_enqueue(const binary_tree_t *tree, Queue *queue)
{
	if (tree && queue)
	{
		in_order_enqueue(tree->left, queue);
		enqueue(queue, tree);
		in_order_enqueue(tree->right, queue);
	}
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	Queue *queue;
	const binary_tree_t *tmp1, *tmp2;

	if (!tree)
		return (0);
	queue = malloc(sizeof(Queue *));
	if (!queue)
		return (0);
	queue->front = queue->rear = NULL;
	in_order_enqueue(tree, queue);
	tmp1 = dequeue(queue);
	tmp2 = dequeue(queue);
	while(tmp2)
	{
		if (tmp1->n > tmp2->n)
		{
			free2(queue);
			return (0);
		}
		tmp1 = tmp2;
		tmp2 = dequeue(queue);
	}
	free2(queue);
	return (1);
}
/**
 *  root->right->left = binary_tree_node(root->right, 97);
 *   binary_tree_print(root);
 *  bst = binary_tree_is_bst(root);
 *  printf("Is %d bst: %d\n", root->n, bst);
 * 
*/
