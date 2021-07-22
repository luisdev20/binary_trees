#include "binary_trees.h"

/**
 * binary_tree_rotate_right - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->left;
	if (tree->left != NULL)
	{
		tree->left = tree->left->right;
		tree->parent->right = tree;
		tree->parent->parent = NULL;
		if (tree->left != NULL)
		{
			tree->left->parent = tree;
		}
		return (tree->parent);
	}
	return (tree);
}
