class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (node == nullptr) return 0;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // Update the diameter if the path through the current node is larger
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};