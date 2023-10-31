#include "binary_trees.h"
/**
 * max - return max of two numbers
 * @a: first number
 * @b: second number
 * Return: max(a, b)
*/
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root of the tree to measure the height
 * Return: the height or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right)) /* if tree is leaf*/
		return (0);

	return (1 + max(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
}
