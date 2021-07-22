#include "binary_trees.h"

/**
 * binary_tree_rotate_left - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL;

	if (tree == NULL)
		return (NULL);

	new_parent = tree->right;
	tree->right = new_parent->left;
	new_parent->parent = tree->parent;

	if (tree->right)
		tree->right->parent = tree;

	tree->parent = new_parent;
	new_parent->left = tree;
	return (new_parent);
}
