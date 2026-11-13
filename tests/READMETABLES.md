# Test Cases
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


# Memory Checker
I used MacOS's native "leaks" command. I compiled both main.cpp and student_tests.cpp into tree_explorer and student_tests respectively with the -g debug flag. I then ran "leaks --atExit -- ./tree_explorer" and "leaks --atExit -- ./student_tests". Both ran perfectly fine with no leaks as evidenced by the following line.
Process 29225: 0 leaks for 0 total leaked bytes.
