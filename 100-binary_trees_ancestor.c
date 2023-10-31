#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);
/**
 * binary_trees_ancestor -  finds the lowest common ancestor
 * of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of
 * the two nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first == second->parent || (!first->parent && binary_tree_depth(second)))
		return ((binary_tree_t *)first);
	if (second == first->parent || (!second->parent && binary_tree_depth(first)))
		return ((binary_tree_t *)second);

	return (binary_trees_ancestor(first->parent, second->parent));
}
/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: the depth or 0 if tree is NULL
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
