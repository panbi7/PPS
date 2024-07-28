class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If the tree is empty, return false
        if (root == nullptr) {
            return false;
        }
        
        // Check if we are at a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            // Check if the targetSum equals the value of the leaf node
            return targetSum == root->val;
        }
        
        // Recursively check the left and right subtrees
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};