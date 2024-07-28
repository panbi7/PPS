#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, nodes);
    nodes.push_back(root);
    inorderTraversal(root->right, nodes);
}

TreeNode* increasingBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    inorderTraversal(root, nodes);
    
    TreeNode* newRoot = nodes[0];
    TreeNode* current = newRoot;
    current->left = nullptr; // The leftmost node should have no left child
    
    for (int i = 1; i < nodes.size(); ++i) {
        current->right = nodes[i];
        nodes[i]->left = nullptr; // Each node should have no left child
        current = current->right;
    }
    current->right = nullptr; // The last node should have no right child
    
    return newRoot;
}

// Helper function to print the right-skewed tree.
void printTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Create the example tree: [5,3,6,2,4,null,8,1,null,null,null,7,9]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    TreeNode* newRoot = increasingBST(root);
    printTree(newRoot); // Should print: 1 2 3 4 5 6 7 8 9 

    return 0;
}
