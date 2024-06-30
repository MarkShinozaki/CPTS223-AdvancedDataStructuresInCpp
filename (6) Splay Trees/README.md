
# Splay Trees

## Introduction to Splay Trees
Splay trees are a type of self-adjusting binary search tree. They are designed to bring recently accessed nodes closer to the root to improve access times for frequently accessed nodes.

## Observations and Ideas
- Height imbalance in trees is problematic only when deeper nodes are accessed.
- Recently accessed nodes are more likely to be accessed again, so bringing them closer to the root optimizes performance.

## Strategy
- After accessing a node (via search or insert), move it to the root using AVL rotations.
- This ensures that any sequence of \( M \) operations will take \( O(M \log N) \) time, making the amortized cost per operation \( O(\log N) \).

## Rotations for Splaying
### Zig-Zag Rotation
When a node is the right child of its parent and the left child of its grandparent (or vice versa), a double rotation (left-right or right-left) is performed.

```cpp
// Zig-Zag Rotation (right-left)
void zigZagRightLeft(TreeNode* &root) {
    rotateRight(root->right);
    rotateLeft(root);
}
```
## Zig-Zig Rotation
- When a node and its parent are both left children or both right children, a double rotation (right-right or left-left) is performed.
```cpp
// Zig-Zig Rotation (left-left)
void zigZigLeftLeft(TreeNode* &root) {
    rotateLeft(root->left);
    rotateLeft(root);
}
```

## Insertion in Splay Trees
- Similar to standard binary search trees, but after insertion, the newly inserted node is splayed to the root.

```cpp
void insert(const Object & x, TreeNode* & root) {
    if (root == nullptr) {
        root = new TreeNode(x);
    } else if (x < root->element) {
        insert(x, root->left);
        splay(root->left, root);
    } else if (root->element < x) {
        insert(x, root->right);
        splay(root->right, root);
    }
}
```
## Deletion in Splay Trees
- Access the node to be removed and splay it to the root.
- After removing the node, the tree is restructured to maintain the splay property

```cpp
void remove(const Object & x, TreeNode* & root) {
    if (root == nullptr) return;
    splay(x, root);
    if (x != root->element) return; // Element not found

    TreeNode* oldRoot = root;
    if (root->left == nullptr) {
        root = root->right;
    } else {
        TreeNode* temp = root->right;
        root = root->left;
        splay(x, root);
        root->right = temp;
    }
    delete oldRoot;
}
```

## Amortized Analysis
- The worst-case time complexity for a single operation is 𝑂(𝑁), but the amortized time complexity for a sequence of operations is 𝑂(log 𝑁).



---

### [Next Section: (7) B Trees](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(7)%20B-Tree)
