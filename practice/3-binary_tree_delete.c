#include "binary_trees.h"

/**
 * binary_tree_insert_right - binary
 * @parent: parent node
 * @value: node value
 * 
 * Return: pointer to the new node
 */

void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return (NULL);
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    free(tree);
}
