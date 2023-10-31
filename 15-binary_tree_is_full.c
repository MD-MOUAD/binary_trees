#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count
 * the number of leaves
 * Return: the number of leaves or 0 if tree is NULL
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (!binary_tree_is_full(tree->left) || !binary_tree_is_full(tree->right))
		return (0);
	else
		return (1);
}
