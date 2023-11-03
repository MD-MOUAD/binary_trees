#include "binary_trees.h"
/**
 * maxim - return max of two numbers
 * @a: first number
 * @b: second number
 * Return: max(a, b)
*/
int maxim(int a, int b)
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
	/* the height of null tree is -1 but for this task it will be  0 */
	if (!tree || (!tree->left && !tree->right)) /* if tree is leaf*/
		return (0);

	return (1 + maxim(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
}
