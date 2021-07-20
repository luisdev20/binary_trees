#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || !tree->parent)
		return (count);

	count = 1 + binary_tree_depth(tree->parent);

	return (count);
}

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	count += 1;
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);

}

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		l = binary_tree_is_full(tree->left);
		r = binary_tree_is_full(tree->right);
		return (l * r);
	}
	return (0);

}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (binary_tree_is_full(tree) == 0)
		return (0);

	if (binary_tree_depth(tree->left) == binary_tree_depth(tree->right))
	{
		l = binary_tree_nodes(tree->left);
		r = binary_tree_nodes(tree->right);
		if (l == r)
			return (1);
	}

	return (0);

}
