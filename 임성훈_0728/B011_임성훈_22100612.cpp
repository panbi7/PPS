class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        if (!root1) return root2;
        if (!root2) return root1;
        
        TreeNode* mergedRoot = new TreeNode(root1->val + root2->val);
        mergedRoot->left = mergeTrees(root1->left, root2->left);
        mergedRoot->right = mergeTrees(root1->right, root2->right);
        
        return mergedRoot;
    }
};

// Function to print the binary tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Helper function to delete the binary tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}