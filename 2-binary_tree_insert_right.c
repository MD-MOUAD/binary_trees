#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node.
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *old;

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
	if (!parent->right) /* if parent has no right-child */
	{
		parent->right = new;
		new->parent = parent;
	}
	else /* If parent already has a right-child*/
	{
		/* the new node must take its place and the old right-child */
		/* must be set as the right-child of the new node */
		old = parent->right;
		parent->right = new;
		new->parent = parent;
		new->right = old;
		old->parent = new;
	}
	return (new);
}
