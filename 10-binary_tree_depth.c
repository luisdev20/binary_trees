#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || !tree->parent)
		return (count);

	count = 1 + binary_tree_depth(tree->parent);

	return (count);
}
