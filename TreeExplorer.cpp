#include "TreeExplorer.h"
#include <queue>
#include <algorithm>

namespace {
    void preorderHelper(const TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        result.push_back(node->value);
        preorderHelper(node->left, result);
        preorderHelper(node->right, result);
    }

    void inorderHelper(const TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        inorderHelper(node->left, result);
        result.push_back(node->value);
        inorderHelper(node->right, result);
    }

    void postorderHelper(const TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        postorderHelper(node->left, result);
        postorderHelper(node->right, result);
        result.push_back(node->value);
    }
}

std::vector<int> preorder(const TreeNode* root) {
    std::vector<int> result;
    preorderHelper(root, result);
    return result;
}

std::vector<int> inorder(const TreeNode* root) {
    std::vector<int> result;
    inorderHelper(root, result);
    return result;
}

std::vector<int> postorder(const TreeNode* root) {
    std::vector<int> result;
    postorderHelper(root, result);
    return result;
}

std::vector<int> levelOrder(const TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::queue<const TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        const TreeNode* current = q.front();
        q.pop();
        result.push_back(current->value);

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return result;
}


std::size_t countNodes(const TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

std::size_t countLeaves(const TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int treeHeight(const TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

long long sumValues(const TreeNode* root) {
    if (!root) return 0;
    return static_cast<long long>(root->value) + sumValues(root->left) + sumValues(root->right);
}


void destroyTree(TreeNode*& root) {
    if (!root) return;
    destroyTree(root->left);   // Delete left subtree
    destroyTree(root->right);  // Delete right subtree
    delete root;               // Delete current node
    root = nullptr;            // Null out the caller's pointer
}