#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    
private:
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right && isLeft) {
            return node->val;
        }
        return dfs(node->left, true) + dfs(node->right, false);
    }
};

int main() {
    // Create the binary tree from the example
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution solution;
    int result = solution.sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << result << endl;
    
    // Clean up dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
