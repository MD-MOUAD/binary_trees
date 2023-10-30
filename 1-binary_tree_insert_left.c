#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child
 * of another node.
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp;

	if (!parent)
		return (NULL);
	/* create new node */
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	/* linking */
	if (!parent->left) /* if parent has no left-child */
	{
		parent->left = new;
		new->parent = parent;
	}
	else /* If parent already has a left-child*/
	{
		/* the new node must take its place and the old left-child */
		/* must be set as the left-child of the new node */
		tmp = parent->left;
		parent->left = new;
		new->parent = parent;
		new->left = tmp;
		tmp->parent = new;
	}
	return (new);
}
