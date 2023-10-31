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
 * binary_tree_height2 - measures the height of a binary tree
 * @tree: a pointer to the root of the tree to measure the height
 * Return: the height or 0 if tree is NULL
*/
size_t binary_tree_height2(const binary_tree_t *tree)
{
	if (!tree)
		return (-1); /* the height of null tree is -1*/

	return (1 + max(binary_tree_height2(tree->left),
					binary_tree_height2(tree->right)));
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * the balance factor
 * Return: the balance factor or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* the Balance Factor is the difference between */
	/* the heights of left and right subtrees */
	return (binary_tree_height2(tree->left) - binary_tree_height2(tree->right));
}
