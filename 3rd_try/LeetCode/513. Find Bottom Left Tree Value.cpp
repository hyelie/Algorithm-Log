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

typedef pair<TreeNode*, int> pti; // second: depth

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pti> q;

        // init
        int answer = root->val;
        int max_depth = 0;


        // BFS init
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* cur_node = q.front().first;
            int cur_depth = q.front().second;
            q.pop();

            if(cur_depth > max_depth){
                max_depth = cur_depth;
                answer = cur_node->val;
            }

            if(cur_node->left){
                q.push({cur_node->left, cur_depth + 1});
            }
            if(cur_node->right){
                q.push({cur_node->right, cur_depth + 1});
            }
        }

        return answer;
    }
};

/*
BFS 쓰는 문제
*/