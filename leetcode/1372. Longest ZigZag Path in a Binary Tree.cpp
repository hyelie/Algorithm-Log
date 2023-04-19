// Runtime 184 ms Beats 41.81%
// Memory 103.2 MB Beats 33.45%

typedef pair<int, int> pii;
class Solution {
public:
    int answer = 0;
    pii dfs(TreeNode* cur){
        int leftlen = 0, rightlen = 0;
        if(cur->left){
            pii leftResult = dfs(cur->left);
            leftlen = max(leftlen, leftResult.second + 1);
            answer = max(answer, max(leftResult.first, leftResult.second + 1));
        }
        if(cur->right){
            pii rightResult = dfs(cur->right);
            rightlen = max(rightlen, rightResult.first + 1);
            answer = max(answer, max(rightResult.first + 1, rightResult.second));
        }
        return {leftlen, rightlen};
    }
    int longestZigZag(TreeNode* root) {
        pii result = dfs(root);
        return answer;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */