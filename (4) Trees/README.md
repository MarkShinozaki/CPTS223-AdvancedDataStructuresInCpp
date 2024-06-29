
# Tree Data Structures

## Overview
- Trees are hierarchical data structures used in various applications like image processing, phylogenetics, organization charts, and large databases.

## Tree Definitions
- **Node**: Basic unit of a tree containing data.
- **Root**: Top node with no parent.
- **Child**: Node directly connected to another node when moving away from the root.
- **Parent**: Node directly connected to another node when moving towards the root.
- **Leaf**: Node with no children.
- **Internal Node**: Node with at least one child.
- **Siblings**: Nodes with the same parent.
- **Path**: Sequence of nodes where each node is connected by an edge to the next node in the sequence.
- **Depth**: Length of the path from the root to a node.
- **Height**: Length of the path from a node to the deepest leaf.
- **Ancestor**: Node on the path from the root to a specific node.
- **Descendant**: Node on the path from a specific node to a leaf.

## Tree Traversals
- **`Pre-order`**: Visit the root, traverse the left subtree, traverse the right subtree.
```cpp
  void preOrder(TreeNode* node) {
      if (node == nullptr) return;
      cout << node->data << " ";
      preOrder(node->left);
      preOrder(node->right);
  }
```

- **`In-order`**: Traverse the left subtree, visit the root, traverse the right subtree.

```cpp
void inOrder(TreeNode* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
```

- **`Post-order`**: Traverse the left subtree, traverse the right subtree, visit the root.
  
```cpp
void postOrder(TreeNode* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}
```

## Expression Trees
- **Definition**: Used to store arithmetic expressions.
- **Components**:
  - Leaves are operands (constants or variables).
  - Internal nodes are operators.
- **Usage**: Commonly used by compilers to parse and evaluate expressions.

## Tree Implementations
- **Vector of Children**: Each node stores a vector of pointers to its children.
```cpp
struct TreeNode {
    Object element;
    vector<TreeNode> children;
};
```
- **List of Children**: Each node stores a list of pointers to its children.
```cpp
struct TreeNode {
    Object element;
    list<TreeNode> children;
};
```

- **First-child, Next-sibling**: Each node stores a pointer to its first child and a pointer to its next sibling.
```cpp
struct TreeNode {
    Object element;
    TreeNode* firstChild;
    TreeNode* nextSibling;
};
```

## Binary Trees
- **Definition**: A tree where each node has at most two children (left and right).
- **Example**:
```cpp
struct BinaryTreeNode {
    Object element;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};
```








---

### [Next Section: (5) AVL Trees](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(5)%20AVL%20Trees)
