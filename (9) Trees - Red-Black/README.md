# Red-Black Trees

## Introduction to Red-Black Trees
Red-Black Trees are a type of self-balancing binary search tree. Operations (search, insert, delete) take \(O(\log N)\) time in the worst case. They require fewer rotations compared to AVL trees, which reduces stack overhead.

## Properties of Red-Black Trees
1. Every node is either red or black.
2. The root is always black.
3. There are no two adjacent red nodes (no red parent-child pairs).
4. Every path from a node to its descendant leaves has the same number of black nodes, known as the "black height".

## Advantages Over AVL Trees
- Red-Black trees provide faster insertion and deletion operations because they require fewer rotations.
- The color attribute in Red-Black trees uses less storage than the height attribute in AVL trees.
- Red-Black trees are used in various libraries (e.g., maps, multimaps, multisets in C++), while AVL trees are more common in databases.

## Structure of Red-Black Trees
Red-Black trees are binary search trees where nodes are colored either red or black. Null pointers are treated as leaf nodes and are considered black.

### Red-Black Tree Node Structure
```cpp
struct RedBlackNode {
    enum Color { RED, BLACK };
    Color color;
    int data;
    RedBlackNode* left;
    RedBlackNode* right;
    RedBlackNode* parent;
};
```
## Insertion in Red-Black Trees
- Insertions follow the standard BST insertion process, and the new node is colored red.
- If the parent of the new node is black, the insertion is complete.
- If the parent is red, it violates the Red-Black tree properties, requiring adjustments through rotations and recoloring.

## Handling Violations During Insertion
1. Color Flip: If the parent and the uncle of the newly inserted node are both red, a color flip is performed.
2. Rotations: If the parent is red but the uncle is black, rotations (single or double) are used to fix the violation.

### Example: Insertion Case Handling

```cpp
void insertFixup(RedBlackNode*& root, RedBlackNode*& node) {
    while (node != root && node->parent->color == RedBlackNode::RED) {
        if (node->parent == node->parent->parent->left) {
            RedBlackNode* uncle = node->parent->parent->right;
            if (uncle && uncle->color == RedBlackNode::RED) {
                node->parent->color = RedBlackNode::BLACK;
                uncle->color = RedBlackNode::BLACK;
                node->parent->parent->color = RedBlackNode::RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(root, node);
                }
                node->parent->color = RedBlackNode::BLACK;
                node->parent->parent->color = RedBlackNode::RED;
                rotateRight(root, node->parent->parent);
            }
        } else {
            RedBlackNode* uncle = node->parent->parent->left;
            if (uncle && uncle->color == RedBlackNode::RED) {
                node->parent->color = RedBlackNode::BLACK;
                uncle->color = RedBlackNode::BLACK;
                node->parent->parent->color = RedBlackNode::RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(root, node);
                }
                node->parent->color = RedBlackNode::BLACK;
                node->parent->parent->color = RedBlackNode::RED;
                rotateLeft(root, node->parent->parent);
            }
        }
    }
    root->color = RedBlackNode::BLACK;
}
```


## Deletion in Red-Black Trees
- Deletion is similar to BST deletion but requires maintaining Red-Black properties.

## Basic Outline of Deletion
1. If the node to be deleted has two children, it is replaced by the smallest node in the right subtree or the largest node in the left subtree.
2. If the node to be deleted or its replacement is red, the new node is colored black and the deletion is complete.
3. If both the node to be deleted and its replacement are black, further adjustments are needed to maintain the black height.

## Example: Deletion Case Handling

```cpp
void deleteFixup(RedBlackNode*& root, RedBlackNode*& node) {
    while (node != root && node->color == RedBlackNode::BLACK) {
        if (node == node->parent->left) {
            RedBlackNode* sibling = node->parent->right;
            if (sibling->color == RedBlackNode::RED) {
                sibling->color = RedBlackNode::BLACK;
                node->parent->color = RedBlackNode::RED;
                rotateLeft(root, node->parent);
                sibling = node->parent->right;
            }
            if (sibling->left->color == RedBlackNode::BLACK && sibling->right->color == RedBlackNode::BLACK) {
                sibling->color = RedBlackNode::RED;
                node = node->parent;
            } else {
                if (sibling->right->color == RedBlackNode::BLACK) {
                    sibling->left->color = RedBlackNode::BLACK;
                    sibling->color = RedBlackNode::RED;
                    rotateRight(root, sibling);
                    sibling = node->parent->right;
                }
                sibling->color = node->parent->color;
                node->parent->color = RedBlackNode::BLACK;
                sibling->right->color = RedBlackNode::BLACK;
                rotateLeft(root, node->parent);
                node = root;
            }
        } else {
            RedBlackNode* sibling = node->parent->left;
            if (sibling->color == RedBlackNode::RED) {
                sibling->color = RedBlackNode::BLACK;
                node->parent->color = RedBlackNode::RED;
                rotateRight(root, node->parent);
                sibling = node->parent->left;
            }
            if (sibling->left->color == RedBlackNode::BLACK && sibling->right->color == RedBlackNode::BLACK) {
                sibling->color = RedBlackNode::RED;
                node = node->parent;
            } else {
                if (sibling->left->color == RedBlackNode::BLACK) {
                    sibling->right->color = RedBlackNode::BLACK;
                    sibling->color = RedBlackNode::RED;
                    rotateLeft(root, sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = RedBlackNode::BLACK;
                sibling->left->color = RedBlackNode::BLACK;
                rotateRight(root, node->parent);
                node = root;
            }
        }
    }
    node->color = RedBlackNode::BLACK;
}
```

## Maintaining Balance
- Balance is maintained through specific patterns of colors and rotations/recoloring after insertions and deletions. Unlike AVL trees, Red-Black trees do not strictly enforce balance but maintain a good overall balance.

## Conclusion
Red-Black trees, with their balance and color properties, ensure efficient operations with 𝑂(log 𝑁)
time complexity for insertions, deletions, and searches. They are widely used in various libraries and applications for their efficient performance and relatively simple implementation






---

### [Next Section: (10) Trees - Parallel Computing](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(10)%20Parallel%20Computing)
