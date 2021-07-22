#include "binary_trees.h"

/**
 * binary_tree_is_avl - insert a new node in a Binary Search Tree
 * @tree: arrya to use
 *
 * Return: If no common ancestor was found return NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	if (!tree->left && !tree->right)
		return (1);

	if (binary_tree_is_bst(tree) != 1 || binary_tree_balance(tree) != 1)
		return (0);
	if (binary_tree_is_avl(tree->right) != 1)
		return (0);

	return (1);
}

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

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left = 1 + binary_tree_height(tree->left);
	right = 1 + binary_tree_height(tree->right);

	if (left > right)
		return (left);
	return (right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height - right_height == 0)
		return (1);
	if (left_height - right_height == 1)
		return (1);
	if (left_height - right_height == -1)
		return (1);

	return (0);
}
