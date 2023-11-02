#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (!tree || !tree->right)
		return (NULL);

	/* tree and pivot exchange childes */
	pivot = tree->left;
	tmp = pivot->right;
	pivot->right = tree;
	tree->left = tmp;
	if (tmp)
		tmp->parent = tree;
	/* now tree and pivot exchange parents */
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}
	return (pivot);
}
