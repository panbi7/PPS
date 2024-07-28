#include <iostream>
#include <vector>
using namespace std;

// 이진 검색 트리 노드 구조체
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리에 값을 삽입하는 함수
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 후위 순회하여 값을 출력하는 함수
void postorderTraversal(TreeNode* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << endl;
}

int main() {
    vector<int> preorder;
    int value;
    
    // 전위 순회 결과를 입력받습니다.
    while (cin >> value) {
        preorder.push_back(value);
    }
    
    // BST를 구성합니다.
    TreeNode* root = nullptr;
    for (int val : preorder) {
        root = insert(root, val);
    }
    
    // 후위 순회 결과를 출력합니다.
    postorderTraversal(root);
    
    return 0;
}
