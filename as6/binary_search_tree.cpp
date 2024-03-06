#include "binary_search_tree.h"
#include <iostream>

// New values insertted left when less-than or right when greater-than-or-equal-to
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Find the node that would be the parent of the proposed_value.
BinaryNode *BinarySearchTree::locate_parent(int proposed_value) {
    if(root == nullptr) {
        return nullptr;
    }

    BinaryNode *current = root;
    while(current->left != nullptr || current->right != nullptr) {
        if(proposed_value < current->value && current->left == nullptr) {
            break;
        } else if (proposed_value >= current->value && current->right == nullptr) {
            break;
        } else if(proposed_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return current;
}

void BinarySearchTree::add(int new_value) {
    // create new node
    BinaryNode *new_node = new BinaryNode{new_value, nullptr, nullptr};

    if(root == nullptr) {
        //assign root to that node
        root = new_node;
    } else {
        // find where it goes
        BinaryNode *parent = locate_parent(new_value);
        //update parent pointer
        if(new_value < parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
}

int BinarySearchTree::remove(int old_value) {
    root = removeRecursive(root, old_value);
    return 0;
}

bool BinarySearchTree::search(int proposed_value) {
    return searchRecursive(root, proposed_value);
}

void BinarySearchTree::in_order_traversal() {
    in_order_traversal_recursive(root);
    std::cout << std::endl; 
}

bool BinarySearchTree::searchRecursive(BinaryNode *current, int proposed_value) {
    if (current == nullptr) {
        return false;
    }
    if (current->value == proposed_value) {
        return true;
    }
    if (proposed_value < current->value) {
        return searchRecursive(current->left, proposed_value);
    }
    return searchRecursive(current->right, proposed_value);
}

void BinarySearchTree::in_order_traversal_recursive(BinaryNode *node) {
    if (node != nullptr) {
        in_order_traversal_recursive(node->left);
        std::cout << node->value << " ";
        in_order_traversal_recursive(node->right);
    }
}

BinaryNode *BinarySearchTree::removeRecursive(BinaryNode *current, int old_value) {
    if (current == nullptr) {
        return nullptr;
    }
    if (old_value < current->value) {
        current->left = removeRecursive(current->left, old_value);
    } else if (old_value > current->value) {
        current->right = removeRecursive(current->right, old_value);
    } else {
        if (current->left == nullptr) {
            BinaryNode *temp = current->right;
            delete current;
            return temp;
        } else if (current->right == nullptr) {
            BinaryNode *temp = current->left;
            delete current;
            return temp;
        }
        BinaryNode *temp = current->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        current->value = temp->value;
        current->right = removeRecursive(current->right, temp->value);
    }
    return current;
}

int main() {
    // Create a binary search tree
    BinarySearchTree tree;

    // Add some values to the tree
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.add(12);
    tree.add(17);

    // Perform in-order traversal to print the elements of the tree
    std::cout << "In-order traversal: ";
    tree.in_order_traversal();

    // Search for elements in the tree
    int value_to_search = 7;
    if (tree.search(value_to_search)) {
        std::cout << value_to_search << " is present in the tree." << std::endl;
    } else {
        std::cout << value_to_search << " is not present in the tree." << std::endl;
    }

    // Remove an element from the tree
    int value_to_remove = 5;
    tree.remove(value_to_remove);

    // Perform in-order traversal after removal
    std::cout << "In-order traversal after removing " << value_to_remove << ": ";
    tree.in_order_traversal();

    return 0;
}
