#include "binary_trees.h"
#include <stdio.h>
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
	if (!tree)
		return (-1);

	return (1 + max(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
}
/**
 * power2 - return n to the power 2
 * @n: the number
 * Return: 2 to the power n
*/
int power2(int n)
{
	if (n == 0)
		return (1);
	return (2 * power2(n - 1));
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is perfect
 * otherwise or if tree is NULL return 0.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* in a perfect tree Total Nodes = 2^(height + 1) - 1 */
	/* I love mathematics :) */
	if (!tree)
		return (0);
	return ((power2(binary_tree_height(tree) + 1) - 1)
			== (int)binary_tree_size(tree));
}
