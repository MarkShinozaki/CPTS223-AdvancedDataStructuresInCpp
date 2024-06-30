
# AVL Trees

## Balanced Binary Search Trees
AVL trees are a type of balanced binary search tree that maintain balance by ensuring that the height of the left and right subtrees of any node differ by at most 1.

## Definition and Properties
- An **AVL tree** is a binary search tree where for every node, the heights of the left and right subtrees differ by at most 1.
- Balance is maintained through rotations during insertions and deletions.

## Maintaining Balance
- Operations like insert, remove, and find in an AVL tree have a time complexity of \(O(\log N)\) because the tree's height is kept at \(O(\log N)\).
- The height \(h(t)\) of a node \(t\) is maintained as:
```cpp
  h(t) = max(h(t->left), h(t->right)) + 1;
```

## Insertions
- Insertions can violate the AVL balance condition.
- Violations are fixed by single or double rotations.
- **Four cases of imbalance during insertions**:
  - **Case 1**: Insert into the left subtree of the left child.
  - **Case 2**: Insert into the right subtree of the left child.
  - **Case 3**: Insert into the left subtree of the right child.
  - **Case 4**: Insert into the right subtree of the right child.
  - Cases 1 and 4 are fixed by single rotations, while Cases 2 and 3 require double rotations.

### Case 1: Single Rotation Right

```cpp
// Right rotation
void rotateWithLeftChild(TreeNode* &k2) {
    TreeNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}
```
### Case 2: Right-Left Double Rotation

```cpp
// Double rotation: first right rotation, then left rotation
void doubleWithRightChild(TreeNode* &k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}
```
### Case 3: Right-Left Double Rotation
```cpp
// Double rotation: first right rotation, then left rotation
void doubleWithRightChild(TreeNode* &k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}
```
### Case 4: Single Rotation Left

```cpp
// Left rotation
void rotateWithRightChild(TreeNode* &k1) {
    TreeNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}
```

## Deletions
- Deletions can also violate the AVL balance condition.
- The deepest node with imbalance is identified and the appropriate rotation is applied.

## Lazy Deletion
- Nodes are marked as deleted but not actually removed until necessary.

## Height Maintenance
- The height of each node is maintained to avoid recalculating it repeatedly.
- After each insertion or deletion, the height values of all nodes from the leaf to the root are updated.

## AVL Tree Node Definition
```cpp
struct AVLTreeNode {
    Object element;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;

    AVLTreeNode(const Object & theElement, AVLTreeNode* lt, AVLTreeNode* rt, int h = 0)
        : element(theElement), left(lt), right(rt), height(h) { }
};
```

## AVL Tree Insert Function

```cpp
void insert(const Object & x, AVLTreeNode* & t) {
    if (t == nullptr)
        t = new AVLTreeNode(x, nullptr, nullptr);
    else if (x < t->element) {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
            if (x < t->left->element)
                rotateWithLeftChild(t); // Case 1
            else
                doubleWithLeftChild(t); // Case 2
    }
    else if (t->element < x) {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
            if (t->right->element < x)
                rotateWithRightChild(t); // Case 4
            else
                doubleWithRightChild(t); // Case 3
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}
```

---

### [Next Section: (6) Splay Trees](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(6)%20Splay%20Trees)

























