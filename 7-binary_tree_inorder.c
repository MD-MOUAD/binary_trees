#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using
 * in-order traversal (lef root right).
 * @tree : a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: 1 if node is root, otherwise 0
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
