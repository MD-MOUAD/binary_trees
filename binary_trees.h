#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

/**
 * struct node - Node structure for a queue element
 * @btree_node: Pointer to a binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct node
{
	const void *btree_node;
	struct node *next;
} Node;

/**
 * struct queue - Queue data structure
 * @front: Pointer to the front node of the queue
 * @rear: Pointer to the rear node of the queue
 */
typedef struct queue
{
	Node *front;
	Node *rear;
} Queue;

/* ========== binary_tree_print.c ========== */
void binary_tree_print(const binary_tree_t *tree);

/* ========== 0-binary_tree_node.c ========== */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* ========== 1-binary_tree_insert_left.c ========== */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* ========== 2-binary_tree_insert_right.c ========== */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* ========== 3-binary_tree_delete.c ========== */
void binary_tree_delete(binary_tree_t *tree);

/* ========== 4-binary_tree_is_leaf.c ========== */
int binary_tree_is_leaf(const binary_tree_t *node);

/* ========== 5-binary_tree_is_root.c ========== */
int binary_tree_is_root(const binary_tree_t *node);

/* ========== 6-binary_tree_preorder.c ========== */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* ========== 7-binary_tree_inorder.c ========== */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* ========== 8-binary_tree_postorder.c ========== */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* ========== 9-binary_tree_height.c ========== */
size_t binary_tree_height(const binary_tree_t *tree);

/* ========== 10-binary_tree_depth.c ========== */
size_t binary_tree_depth(const binary_tree_t *tree);

/* ========== 11-binary_tree_size.c ========== */
size_t binary_tree_size(const binary_tree_t *tree);

/* ========== 12-binary_tree_leaves.c ========== */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* ========== 13-binary_tree_nodes.c ========== */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* ========== 14-binary_tree_balance.c ========== */
int binary_tree_balance(const binary_tree_t *tree);

/* ========== 15-binary_tree_is_full.c ========== */
int binary_tree_is_full(const binary_tree_t *tree);

/* ========== 16-binary_tree_is_perfect.c ========== */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* ========== 17-binary_tree_sibling.c ========== */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* ========== 18-binary_tree_uncle.c ========== */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));


#endif /* BINARY_TREES_H */
