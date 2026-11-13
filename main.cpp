#include "TreeExplorer.h"
#include <iostream>
#include <vector>

void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void analyzeTree(const std::string& treeName, TreeNode*& root) {
    std::cout << "--- " << treeName << " ---\n";
    printVector("Preorder  ", preorder(root));
    printVector("Inorder   ", inorder(root));
    printVector("Postorder ", postorder(root));
    printVector("LevelOrder", levelOrder(root));
    
    std::cout << "Nodes:  " << countNodes(root) << "\n";
    std::cout << "Leaves: " << countLeaves(root) << "\n";
    std::cout << "Height: " << treeHeight(root) << "\n";
    std::cout << "Sum:    " << sumValues(root) << "\n\n";

    destroyTree(root);
    std::cout << treeName << " destroyed. Root is " << (root == nullptr ? "null" : "NOT null") << ".\n\n";
}

int main() {
    TreeNode* rootA = new TreeNode{50};
    rootA->left = new TreeNode{30};
    rootA->right = new TreeNode{70};
    rootA->left->left = new TreeNode{20};
    rootA->left->right = new TreeNode{40};
    rootA->right->left = new TreeNode{60};
    rootA->right->right = new TreeNode{80};

    TreeNode* rootB = new TreeNode{10};
    rootB->left = new TreeNode{30};
    rootB->right = new TreeNode{20};
    rootB->left->right = new TreeNode{5};
    rootB->right->right = new TreeNode{15};

    analyzeTree("Tree A", rootA);
    analyzeTree("Tree B", rootB);

    return 0;
}