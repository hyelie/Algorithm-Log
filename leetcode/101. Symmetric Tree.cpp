// Runtime 0 ms Beats 100%
// Memory 16.4 MB Beats 84.12%
class Solution {
public:
    bool inorder(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL) return true;
        // if(left == NULL && right != NULL) return false;
        // if(left != NULL && right == NULL) return false;
        // 이 두 줄을 아래 줄로 표현할 수 있다.
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;

        return inorder(left->left, right->right) && inorder(left->right, right->left);    
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return inorder(root->left, root->right);
    }
};