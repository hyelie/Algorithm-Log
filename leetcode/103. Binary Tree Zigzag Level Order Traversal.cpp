// 처음 풀었던 버전 : 7ms(27.9%), 12.2MB(17.21%)

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

typedef pair<TreeNode*, int> pni;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int maxDepth = -1;
        vector<vector<int>> answer;

        // BFS init
        queue<pni> q;
        q.push({root, 0});

        while(!q.empty()){
            // pop
            TreeNode* curNode = q.front().first;
            int curDepth = q.front().second;
            q.pop();
            if(curNode == NULL) continue;

            // if depth is deeper, than add
            if(curDepth > maxDepth){
                answer.push_back({});
                maxDepth = curDepth;
            }
            answer[curDepth].push_back(curNode->val);

            q.push({curNode->left, curDepth + 1});
            q.push({curNode->right, curDepth + 1});
        }

        for(int i = 1; i<answer.size(); i += 2){
            reverse(answer[i].begin(), answer[i].end());
        }
        return answer;
    }
};