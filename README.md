##  Programming Assignments

### [Programming Assignment 1](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Programming-Assignments/PA%201)

#### Description 
##### Key Topics Covered:

1. C++ Programming with Templates:
  - Develop a C++ program using templates, specifically for creating a linked list to store data.

2. Linux Commands:
  - Learn and use 30 popular Linux commands, storing them in a CSV file and using them in the game.

4. Data Structures:
  - Implement a linked list using a class template with two parameters.
  - Store user profiles in an array, and compare the pros and cons of using arrays vs. linked lists.

4. File Operations:
  - Open, edit, parse, and close `.csv` files in C++.

##### Assignment Overview:
- Objective: Create an interactive, text-based single-player game where the player matches Linux commands with their descriptions.
- Game Features:
  - Players earn or lose points based on correct or incorrect matches.
  - Commands and descriptions are stored in a commands.csv file.
  - Player profiles are stored in a profiles.csv file.
- Main Menu Options:
  - Game Rules
  - Play Game
  - Load Previous Game
  - Add Command
  - Remove Command
  - Exit
    
##### Design Considerations:
- Implement linked lists without using the Standard Template Library (STL).
- Populate the linked list with command-description pairs and update the user profile stored in an array.
- Discuss advantages and disadvantages of using linked lists and arrays in the assignment's context.

--- 



### [Programming Assignment 2 ](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Programming-Assignments/PA%202)

#### Description 

##### Key Topics Covered:
1. AVL Trees:
  - Design and implement an AVL tree data structure using class templates in C++.
  - Understand the balancing properties of AVL trees where the height difference between the left and right subtrees at every node is at most 

2. Class Templates:

- Create a class template `AVLNode` for the nodes in the `AVL tree`, including necessary constructors, destructors, data members (generic type `T`, pointers to left and right children, and node height).
- Create a class template `AVLTree` for the AVL tree itself, with functions to manage the tree, such as inserting values, checking tree height, validating the tree’s balance, and checking for the presence of a value.

3. C++ Programming Skills:

- Implement the AVL tree operations in C++.
- Write CMake configuration files (`CMakeLists.txt`) to build and verify the project in a cross-platform manner using `cmake`.

4. Testing:
- Create test cases using sequences of odd numbers from 1 to 100 in different orders (ascending, descending, random).
- Insert these sequences into AVL trees and validate their structure by checking tree height and whether the tree is balanced.

#### Assignment Requirements:
##### Implementation:
- Develop the AVLNode and AVLTree classes and their functions, ensuring the AVL tree maintains its balance after each insertion.
- Implement the necessary test cases and validate the functionality of the AVL tree.

##### Verification:
- Use cmake to build the project, ensuring it works across platforms.
- Validate the tree's balance and the correctness of the contains() function using predefined test cases.

--- 

### [Programming Assignment 3 ](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Programming-Assignments/PA%203)

#### Description 

##### Key Topics Covered:

1. Hash Tables:
- Separate Chaining: Implement a hash table where data is stored in a vector of linked lists.
- Linear Probing: Implement a hash table using a single vector with linear probing and lazy deletion.

2. C++ Programming Skills:

- Use class templates to design and implement the hash tables.
- Implement rehashing logic when the load factor exceeds 0.75, ensuring efficient distribution of elements across buckets.

3. Hash Table Operations:

- Implement essential hash table functions such as insertion, deletion, search, rehashing, and clearing the hash table.
- Ensure that the public interfaces provided in the starter code are properly implemented.

##### Assignment Requirements:
- Separate Chaining (40 pts):

  - Implement the hash table using a vector of lists with the C++ STL std::vector and std::list.
  - Implement functions for handling operations such as insertion, deletion, search, and rehashing.

- Linear Probing (40 pts):

  - Implement the hash table using a single vector, with careful management of deleted elements (lazy deletion).
  - Ensure proper handling of probing and rehashing.

- Test Cases (10 pts):

  - Test the hash tables with predefined cases such as inserting 100,000 records, searching for keys, erasing keys, and clearing the table.
  - Measure and output the time taken for certain operations.

- Other Requirements (10 pts):

Use cmake to build the project, ensuring cross-platform compatibility.
