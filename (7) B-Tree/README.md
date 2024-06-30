# B-Trees and B+ Trees

## B-Trees

### Introduction to B-Trees
B-Trees are a type of self-balancing search tree optimized for systems that read and write large blocks of data, such as databases and file systems. Each node in a B-tree can contain multiple keys and children, reducing the tree's height and minimizing the number of disk accesses required.

### Properties of B-Trees
- All leaves are at the same level.
- A B-tree of order \( m \) can have at most \( m \) children and \( m-1 \) keys.
- The root node has at least two children if it is not a leaf node.
- Every internal node, except the root, has at least \( \lceil m/2 \rceil \) children.
- Nodes are maintained to be at least half full.

### Operations on B-Trees
#### Search
Search operation is similar to binary search but works on multiple keys in each node.
```cpp
bool search(TreeNode* node, int key) {
    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) {
        i++;
    }
    if (i < node->numKeys && key == node->keys[i]) {
        return true;
    }
    if (node->isLeaf) {
        return false;
    }
    return search(node->children[i], key);
}
```

#### Insertion
- Insertion adds a key to the appropriate leaf node. If the leaf node overflows, it splits, and the middle key is promoted to the parent node.
```cpp
void insert(TreeNode* &root, int key) {
    if (root->numKeys == maxKeys) {
        TreeNode* newRoot = new TreeNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        root = newRoot;
    }
    insertNonFull(root, key);
}
```
#### Deletion
- Deletion removes a key and may cause underflow. If a node underflows, it borrows from a sibling or merges with a sibling.
```cpp
void deleteKey(TreeNode* &root, int key) {
    deleteRec(root, key);
    if (root->numKeys == 0) {
        TreeNode* temp = root;
        if (!root->isLeaf) {
            root = root->children[0];
        } else {
            root = nullptr;
        }
        delete temp;
    }
}
```
### Advantages of B-Trees
- Efficient for systems that read and write large blocks of data.
- Keeps the height of the tree low, ensuring fast access times.
- Minimizes the number of disk accesses required for search, insertion, and deletion operations.

## B+ Trees
### Introduction to B+ Trees
- B+ Trees are an extension of B-Trees that provide better performance for range queries. All values are stored at the leaf level, with internal nodes only storing keys to guide searches.

### Properties of B+ Trees
- All data records are stored at the leaf nodes.
- Internal nodes contain keys and pointers to guide the search but do not store data records.
- Leaf nodes are linked together to provide ordered data traversal.

### Operations on B+ Trees

#### Search
- Search starts at the root and traverses down to the appropriate leaf node, similar to B-Trees.
```cpp
TreeNode* search(TreeNode* node, int key) {
    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) {
        i++;
    }
    if (i < node->numKeys && key == node->keys[i]) {
        return node;
    }
    if (node->isLeaf) {
        return nullptr;
    }
    return search(node->children[i], key);
}
```

#### Insertion
- Insertion adds a key to the appropriate leaf node. If the leaf node overflows, it splits, and the middle key is promoted to the parent node.

```cpp
void insert(TreeNode* &root, int key) {
    if (root->numKeys == maxKeys) {
        TreeNode* newRoot = new TreeNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        root = newRoot;
    }
    insertNonFull(root, key);
}
```
#### Deletion
- Deletion removes a key from the leaf node and may cause underflow. If a node underflows, it borrows from a sibling or merges with a sibling.

```cpp
void deleteKey(TreeNode* &root, int key) {
    deleteRec(root, key);
    if (root->numKeys == 0) {
        TreeNode* temp = root;
        if (!root->isLeaf) {
            root = root->children[0];
        } else {
            root = nullptr;
        }
        delete temp;
    }
}
```

## Advantages of B+ Trees
- Efficient for systems that require range queries and ordered data traversal.
- Leaf nodes are linked, allowing for fast sequential access.
- Keeps internal nodes small, optimizing disk accesses.


---

### [Next Section: (8) Trees - Set & Map](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(8)%20Trees%20-%20Set%20%26%20Map)
