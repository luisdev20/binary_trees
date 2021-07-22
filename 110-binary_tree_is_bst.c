#include "binary_trees.h"

/**
 * binary_tree_is_bst - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (less(tree->left, tree->n) && greater(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * less - verify is node value is less root value
 * @tree: a pointer to the first node
 * @n: root value
 * Return: return 1 if are right or 0 if failes
 */
int less(const binary_tree_t *tree, int n)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n < n)
	{
		left = less(tree->left, n);
		right = less(tree->right, n);
		if (left != 0 && right != 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * greater - verify is node value is greater root value
 * @tree: a pointer to the first node
 * @n: root value
 * Return: return 1 if are right or 0 if failes
 */
int greater(const binary_tree_t *tree, int n)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (tree->n > n)
	{
		left = greater(tree->left, n);
		right = greater(tree->right, n);
		if (left != 0 && right != 0)
		{
			return (1);
		}
	}
	return (0);
}
