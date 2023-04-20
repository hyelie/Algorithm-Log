// Runtime 12 ms Beats 45.41%
// Memory 17.4 MB Beats 25.97%

typedef long long ll;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q; // .first : root, .second : index

        
        ll answer = -1;
        q.push({root, 0});
        while(!q.empty()){
            int curLevelSize = q.size();

            answer = max(answer, q.back().second - q.front().second + 1); // answer : max sign integer
            int startIdx = q.front().second;
            while(curLevelSize--){
                TreeNode* topNode = q.front().first;
                int topIndex = q.front().second - startIdx;
                q.pop();

                if(topNode->left){
                    q.push({topNode->left, 2L*topIndex});
                }
                if(topNode->right){
                    q.push({topNode->right, 2L*topIndex + 1});
                }
            }

        }

        return (int)answer;
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