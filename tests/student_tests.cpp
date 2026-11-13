#include "../TreeExplorer.h"
#include <iostream>
#include <vector>
#include <string>

int testsPassed = 0;
int testsTotal = 0;

template <typename T>
void check(const std::string& testName, const T& actual, const T& expected) {
    testsTotal++;
    if (actual == expected) {
        std::cout << "[PASS] " << testName << "\n";
        testsPassed++;
    } else {
        std::cout << "[FAIL] " << testName << "\n";
        // Note: For vectors, you might want to add a loop to print actual vs expected 
        // if a test fails, but this basic check works perfectly for our needs.
    }
}

void printSection(const std::string& name) {
    std::cout << "\n=== " << name << " ===\n";
}

void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Starting Student Tests...\n";

    // ---------------------------------------------------------
    printSection("1. Empty Tree & Repeated Destruction");
    TreeNode* emptyRoot = nullptr;
    
    check("Empty Preorder", preorder(emptyRoot), std::vector<int>{});
    check("Empty Inorder", inorder(emptyRoot), std::vector<int>{});
    check("Empty Postorder", postorder(emptyRoot), std::vector<int>{});
    check("Empty Nodes", countNodes(emptyRoot), std::size_t(0));
    check("Empty Height", treeHeight(emptyRoot), 0);
    check("Empty Sum", sumValues(emptyRoot), 0LL);
    
    destroyTree(emptyRoot); // Should be safe
    destroyTree(emptyRoot); // Repeated destruction should be safe
    check("Empty Root Null Check After Multiple Destruction Calls", emptyRoot == nullptr, true);


    // ---------------------------------------------------------
    printSection("2. Singleton with value -4");
    TreeNode* singleton = new TreeNode{-4};
    
    check("Singleton Preorder", preorder(singleton), std::vector<int>{-4});
    check("Singleton Inorder", inorder(singleton), std::vector<int>{-4});
    check("Singleton Postorder", postorder(singleton), std::vector<int>{-4});
    check("Singleton Nodes", countNodes(singleton), std::size_t(1));
    check("Singleton Leaves", countLeaves(singleton), std::size_t(1));
    check("Singleton Height", treeHeight(singleton), 1);
    check("Singleton Sum", sumValues(singleton), -4LL);
    
    destroyTree(singleton);
    check("Singleton Null Check After Destruction Call", singleton == nullptr, true);


    // ---------------------------------------------------------
    printSection("3. Left-only and Right-only Chains");
    // Left chain: 1 -> 2 -> 3 -> 4
    TreeNode* leftChain = new TreeNode{1};
    leftChain->left = new TreeNode{2};
    leftChain->left->left = new TreeNode{3};
    leftChain->left->left->left = new TreeNode{4};

    check("Left Chain Leaves", countLeaves(leftChain), std::size_t(1));
    check("Left Chain Height", treeHeight(leftChain), 4);
    std::cout << std::endl;

    std::cout << "Predicted Left Chain Preorder Traversal: 1 2 3 4" << std::endl;
    printVector("Actual Left Chain Preorder Traversal", preorder(leftChain));
    check("Left Chain Preorder", preorder(leftChain), std::vector<int>{1, 2, 3, 4});
    std::cout << std::endl;

    std::cout << "Predicted Left Chain Inorder Traversal: 4 3 2 1" << std::endl;
    printVector("Actual Left Chain Inorder Traversal", inorder(leftChain));
    check("Left Chain Inorder", inorder(leftChain), std::vector<int>{4, 3, 2, 1});
    std::cout << std::endl;

    std::cout << "Predicted Left Chain Postorder Traversal: 4 3 2 1" << std::endl;
    printVector("Actual Left Chain Postorder Traversal", postorder(leftChain));
    check("Left Chain Postorder", postorder(leftChain), std::vector<int>{4, 3, 2, 1});
    std::cout << std::endl << std::endl;

    // Right chain: 1 -> 2 -> 3 -> 4
    TreeNode* rightChain = new TreeNode{1};
    rightChain->right = new TreeNode{2};
    rightChain->right->right = new TreeNode{3};
    rightChain->right->right->right = new TreeNode{4};

    check("Right Chain Leaves", countLeaves(rightChain), std::size_t(1));
    check("Right Chain Height", treeHeight(rightChain), 4);
    std::cout << std::endl;

    std::cout << "Predicted Right Chain Preorder Traversal: 1 2 3 4" << std::endl;
    printVector("Actual Right Chain Preorder Traversal", preorder(rightChain));
    check("Right Chain Preorder", preorder(rightChain), std::vector<int>{1, 2, 3, 4});
    std::cout << std::endl;

    std::cout << "Predicted Right Chain Inorder Traversal: 1 2 3 4" << std::endl;
    printVector("Actual Right Chain Inorder Traversal", inorder(rightChain));
    check("Right Chain Inorder", inorder(rightChain), std::vector<int>{1, 2, 3, 4});
    std::cout << std::endl;

    std::cout << "Predicted Right Chain Postorder Traversal: 4 3 2 1" << std::endl;
    printVector("Actual Right Chain Postorder Traversal", postorder(rightChain));
    check("Right Chain Postorder", postorder(rightChain), std::vector<int>{4, 3, 2, 1});
    std::cout << std::endl;



    destroyTree(leftChain);
    destroyTree(rightChain);
    check("LeftChain Null Check After Destruction Call", leftChain == nullptr, true);
    check("RightChain Null Check After Destruction Call", rightChain == nullptr, true);


    // ---------------------------------------------------------
    printSection("4. Duplicates, Zero, and Negative Values");
    /* Shape:
             0
            / \
          -5   0
                \
                -5
    */
    TreeNode* dupTree = new TreeNode{0};
    dupTree->left = new TreeNode{-5};
    dupTree->right = new TreeNode{0};
    dupTree->right->right = new TreeNode{-5};

    check("DupTree Nodes", countNodes(dupTree), std::size_t(4));
    check("DupTree Leaves", countLeaves(dupTree), std::size_t(2));
    check("DupTree Sum", sumValues(dupTree), -10LL);
    check("DupTree Preorder", preorder(dupTree), std::vector<int>{0, -5, 0, -5});
    check("DupTree Inorder", inorder(dupTree), std::vector<int>{-5, 0, 0, -5});
    check("DupTree Postorder", postorder(dupTree), std::vector<int>{-5, -5, 0, 0});
    
    destroyTree(dupTree);
    check("DupTree Null Check After Destruction Call", dupTree == nullptr, true);


    // ---------------------------------------------------------
    printSection("5. Vector Independence");
    TreeNode* indTree = new TreeNode{10};
    indTree->left = new TreeNode{20};
    
    std::vector<int> firstCall = preorder(indTree);
    firstCall.push_back(999); // Mutate the returned vector
    
    std::vector<int> secondCall = preorder(indTree);
    check("Vector Independence", secondCall, std::vector<int>{10, 20}); // Should NOT contain 999
    
    destroyTree(indTree);
    check("IndTree Null Check After Destruction Call", indTree == nullptr, true);

    // ---------------------------------------------------------
    printSection("6. Destroy, Rebuild, Destroy");
    TreeNode* rebuildRoot = new TreeNode{100};
    destroyTree(rebuildRoot);
    check("RebuildRoot Null Check After Destruction Call", rebuildRoot == nullptr, true);
    
    rebuildRoot = new TreeNode{200}; // Reusing the same variable
    rebuildRoot->left = new TreeNode{300};
    check("Rebuild Sum After Rebuilding", sumValues(rebuildRoot), 500LL);
    
    destroyTree(rebuildRoot);
    check("RebuildRoot Null Check After Second Destruction Call", rebuildRoot == nullptr, true);


    // ---------------------------------------------------------
    printSection("7. Perfect Binary Tree");
    /* Shape:
             1
            / \
           2   3
    */
    TreeNode* perfectTree = new TreeNode{1};
    perfectTree->left = new TreeNode{2};
    perfectTree->right = new TreeNode{3};

    check("PerfectTree Height", treeHeight(perfectTree), 2);
    check("PerfectTree Leaves", countLeaves(perfectTree), std::size_t(2));
    check("PerfectTree LevelOrder", levelOrder(perfectTree), std::vector<int>{1, 2, 3});

    destroyTree(perfectTree);
    check("PerfectTree Null Check After Destruction Call", perfectTree == nullptr, true);


    // ---------------------------------------------------------
    std::cout << "\nTest Summary: " << testsPassed << " / " << testsTotal << " passed.\n";

    return 0;
}