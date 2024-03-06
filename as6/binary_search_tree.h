#include "binary_node.h"

class BinarySearchTree {
    BinaryNode *root;
    BinaryNode *locate_parent(int proposed_value);
    BinaryNode *removeRecursive(BinaryNode *current, int old_value);
    bool searchRecursive(BinaryNode *current, int proposed_value);
    void in_order_traversal_recursive(BinaryNode *node);

    public:
        BinarySearchTree();
        void add(int new_value);
        int remove(int old_value);
        bool search(int proposed_value);
        void in_order_traversal();
};