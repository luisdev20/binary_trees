#include "binary_trees.h"

/**
 * binary_tree_rotate_left - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->right;
	if (tree->right != NULL)
	{
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;
		if (tree->right != NULL)
		{
			tree->right->parent = tree;
		}
		return (tree->parent);
	}
	return (tree);
}
