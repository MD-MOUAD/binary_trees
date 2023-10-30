#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using
 * pre-order traversal (root lef right).
 * @tree : a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: 1 if node is root, otherwise 0
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
