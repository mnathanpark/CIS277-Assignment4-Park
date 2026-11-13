# CIS-277 Assignment 4: Binary Tree Explorer

## Student
Nathan Park

## Design
Each TreeNode has a integer value and two pointers pointing to the left and right children.
An empty tree is represented as a nullptr. 
Each traversal method (preorder, inorder, and postorder) will pass a vector by reference to store the integer values.
Each node is allocated with new in main.cpp. The destoryTree function will take a pointer to the root of the tree as its parameter and use postorder traversal to delete each node in the tree and set the pointers to nullptr.

## How to Compile
g++ -std=c++23 -Wall -Wextra -pedantic main.cpp TreeExplorer.cpp -o tree_explorer
g++ -std=c++23 -Wall -Wextra -pedantic -I. tests/student_tests.cpp TreeExplorer.cpp -o student_tests

## How to Run
./tree_explorer
./student_tests

## Tests and Results
1) 
Empty Tree and Repeated Destruction

Input: root = nullptr
Expected Output: All Traversals: (), Count/Height/Sum: 0, Repeated Destruction: safe
Actual Output: All Traversals: (), Count/Height/Sum: 0, Repeated Destruction: safe
Corrections: None

2) 
Singleton with Value -4

Input: Single Node with value -4
Expected Output: All Traversals: (-4), Count/Height: 1, Sum: -4
Actual Output: All Traversals: (-4), Count/Height: 1, Sum: -4
Corrections: None

3) 
Left-only and Right-only Chains

Input (Left Chain): Binary Tree with only left children with values 1, 2, 3, 4
Expected Output (Left Chain): Preorder (1 2 3 4), Inorder (4 3 2 1), Postorder (4 3 2 1). Leaves count: 1, Height: 4.
Actual Output (Left Chain): Preorder (1 2 3 4), Inorder (4 3 2 1), Postorder (4 3 2 1). Leaves count: 1, Height: 4.
Corrections: None

Input (Right Chain): Binary Tree with only right children with values 1, 2, 3, 4
Expected Output (Right Chain): Preorder (1 2 3 4), Inorder (1 2 3 4), Postorder (4 3 2 1). Leaves count: 1, Height: 4.
Actual Output (Right Chain): Preorder (1 2 3 4), Inorder (1 2 3 4), Postorder (4 3 2 1). Leaves count: 1, Height: 4.
Corrections: None

4) 
Duplicates, Zero, and Negative Values

Input: Binary tree with shape
             0
            / \
          -5   0
                \
                -5
Expected Output: Preorder (0 -5 0 -5), Inorder (-5 0 0 -5), Postorder (-5 -5 0 0). Count: 4, Height: 3, Sum: -10
Actual Output: Preorder (0 -5 0 -5), Inorder (-5 0 0 -5), Postorder (-5 -5 0 0). Count: 4, Height: 3, Sum: -10
Corrections: None

5) 
Vector Independence

Input: Binary tree with shape
             10
            /
          20
Expected Output: Vector with values (10, 20) that is not mutated.
Actual Output: Vector with values (10, 20)
Corrections: None

6) 
Destroy, Rebuild, Destroy

Input: Node with value 100 and the same node with value 200 and left child with value 300 after it has been destroyed.
Expected Output: Safe destructions for all trees, and sum of 500 for second tree.
Actual Output: Safe destructions for all trees, and sum of 500 for second tree.
Corrections: None

7) 
Perfect Binary Tree

Input: Binary tree with shape
             1
            / \
           2   3
Expected Output: Levelorder (1 2 3), Count: 3, Height: 2, Sum: 6
Actual Output: Levelorder (1 2 3), Count: 3, Height: 2, Sum: 6
Corrections: None

# Initial Plan
Each TreeNode has a integer value and two pointers pointing to the left and right children.
An empty tree is represented as a nullptr. 
Each traversal method (preorder, inorder, and postorder) will pass a vector by reference to store the integer values.
Each node is allocated with new in main.cpp. The destoryTree function will take a pointer to the root of the tree as its parameter and use postorder traversal to delete each node in the tree and set the pointers to nullptr.

For tree A: 
Root is 50.
Leaves are 20, 40, 60, 80.
50 is the parent of 30 and 70.
30 is the parent of 20 and 40.
70 is the parent of 60 and 80.

Predicted Traversals:
preorder traversal: (50, 30, 20, 40, 70, 60, 80)
inorder traversal: (20, 30, 40, 50, 60, 70, 80)
postorder traversal: (20, 40, 30, 60, 80, 70, 50)
levelorder traversal: (50, 30, 70, 20, 40, 60, 80)

Node count is 7.
Leaf count is 4.
Height is 3.
Sum is 350.

For tree B:
Root is 10.
Leaves are 5, 15.
10 is the parent of 30 and 20.
30 is the parent of 5.
20 is parent of 15.

Predicted traversals:
preorder traversal: (10, 30, 5, 20, 15)
inorder traversal: (30, 5, 10, 20, 15)
postorder traversal: (5, 30, 15, 20, 10)
levelorder traversal: (10, 30, 20, 5, 15)

Node count is 5.
Leaf count is 2.
Height is 3.
Sum is 80.

Reasoning for preorder traversal of tree B:
We start at the root node 10 and record it. Then we look at the left child 30 and record it. 30 has no left child, but has a right child of 5, which we record. 5 has no children of its own, so the recursive calls all resolve on the left side of the tree. Then we look at the 20, the right child of 10, and record it. 20 has no left child, but has a right child of 15, which we record. 15 has no children of its own, so the recursive calls all resolve on the right side, and the traversal is finished.

## Analysis Questions
Trace the preorder, inorder, and postorder processing steps for the subtree rooted at 30 in Tree A. Explain why the sequences change while the sum does not.
Preorder: Visit 30 (record 30), recurse left to 20 (record 20, 20 has no children), then recurse right to 40 (record 40, 40 has no children). Sequence: 30, 20, 40
Inorder: Recurse left to 20 (left null, record 20, right null), return to 30 (record 30), then recurse right to 40 (left null, record 40, right null). Sequence: 20, 30, 40.
Postorder: Recurse left to 20 (children null, record 20), recurse right to 40 (children null, record 40), then return to 30 (record 30). Sequence: 20, 40, 30
Each traversal method only changes the order in which each node is visited. However, it does not change the fact that all traversal methods only visit each node once, so the sum will always be the same. 

Explain why Tree B is a binary tree but not a BST, using a specific violated ordering relationship. Why is its inorder sequence not sorted?
Tree B is a binary tree because each node has at most 2 children. However, it is not a BST because a BST requires that every node's value be strictly greater than all values in its left subtree and strictly less than all values in its right subtree. Tree B breaks this because 5 is a right child of 30, and 15 is a right child of 20.
An inorder traversal produces ascending sorted order only when the underlying tree obeys the BST ordering rule at every node. Because inorder follows pointer structure rather than sorting values, it visits 30 and its right child 5 before root 10, producing 30, 5, 10, 20, 15.

Give the depth of node 40 in Tree A and distinguish depth in edges from this assignment's height in levels.
The depth of node 40 is Tree A is 2 because there are 2 edges. Depth is measured by the number of edges between two nodes going downwards. Height is measured in levels going upwards.

Explain how the FIFO queue produces level order. Connect this to the queue behavior from earlier work.
A queue enforces FIFO behavior. Items are removed from the front in the exact order they were added to the back. Starting with the root enqueued, each iteration dequeues the front node, records its value, and enqueues its existing left child followed by its right child. Because all nodes at level n are inserted into the queue before any of their children at level n + 1, all level-n nodes must be dequeued and processed before the queue reaches level n + 1. Enqueuing left children before right children ensures every level is visited strictly left to right.

For n nodes, height h, and maximum level width w, explain the time and auxiliary space for depth-first traversal, level-order traversal, measurements, and destruction. Discuss the O(n) returned vector separately from the call stack or queue. Compare the height of a balanced tree with a chain. Explain why a normal traversal does not need dynamic-programming tabulation.
Time Complexity: Depth-first traversals (preorder, inorder, postorder), levelOrder, structural measurements (countNodes, countLeaves, treeHeight, sumValues), and destroyTree all run in O(n) time. Each of the n nodes is visited once and performs O(1) work per visit.
Auxiliary Working Space (excluding the O(n) tree itself): Depth-first traversals, measurements, and destruction: O(h) auxiliary stack space for the recursive call stack, since the maximum number of active stack frames at one time equals the tree's height h. Passing the output vector by reference (std::vector<int>&) avoids copying vectors across recursive calls.Level-order traversal: O(w) auxiliary queue space, because std::queue holds at most one full level's worth of nodes (bounded by maximum width w) at any point during execution.
Returned Output Space: Separately from working memory, the four traversal functions allocate and return a std::vector<int> storing all n values, requiring O(n) output space. Measurements and destroyTree return scalars or void, requiring O(1) output space.
Balanced Tree vs. Chain Height: In a balanced binary tree, capacity doubles at each level, yielding height h = O(log(n)), which keeps recursive stack usage low (O(log(n))) while max width w reaches O(n). In a single-branch chain, every node has at most one child, so h = n = O(n) and w = 1, pushing recursive stack usage to O(n) and risking stack overflow on deep trees.
Dynamic programming tabulation caches answers to overlapping subproblems that are recomputed multiple times (such as fib(k) in naive Fibonacci recursion). Because a valid binary tree is acyclic with no shared child pointers, every subtree is completely disjoint and each node is visited once along a unique path from the root—there are no repeated subproblems to tabulate.

Explain why deletion uses postorder and what TreeNode*& changes in the caller. What would go wrong if the parent were deleted before reading its child pointers?
Postorder guarantees that a node's left and right subtrees are completely freed before the parent node itself is deleted with delete root.
Deleting the parent first immediately frees its memory back to the allocator. Attempting to read root->left or root->right afterward dereferences freed memory, causing undefined behavior, or leaks the entire child subtrees if their addresses were not saved beforehand.
Passing the root pointer by reference binds root directly to the caller's pointer variable rather than making a local copy of the address. Setting root = nullptr after delete root updates the caller's pointer to nullptr instead of leaving a dangling pointer, making subsequent null checks accurate and repeated calls to destroyTree(root) completely safe.

## AI Use
Gemini was used in making the README file, in order to format the answers.