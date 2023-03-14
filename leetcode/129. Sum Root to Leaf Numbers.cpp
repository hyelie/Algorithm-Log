// Runtime 3 ms Beats 62.17%
// Memory 9.2 MB Beats 52.62%

class Solution {
public:
    int sum = 0;
    void DFS(TreeNode *cur, int prev){
        // calculate current value using prev value
        int suffixSum = 10 * prev + cur->val;

        // base case : leaf
        if(cur->left == NULL && cur->right == NULL){
            sum += suffixSum;
            return;
        }

        // not leaf, then deeper
        if(cur->left) DFS(cur->left, suffixSum);
        if(cur->right) DFS(cur->right, suffixSum);
    }
    int sumNumbers(TreeNode* root) {
        DFS(root, 0);
        return sum;
    }
};