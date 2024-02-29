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

typedef pair<TreeNode*, int> pti;


class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<pti> q;
        vector<vector<int>> layers;

        q.push({root, 0});
        while(!q.empty()){
            TreeNode *cur = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level % 2 == 1 && cur->val % 2 == 1){ // odd layer but odd
                return false;
            }
            if(level % 2 == 0 && cur->val % 2 == 0){ // even layer but even
                return false;
            }

            if(layers.size() < level + 1){
                layers.push_back({cur->val});
            }
            else{
                layers.back().push_back(cur->val);
            }

            if(cur->left){
                q.push({cur->left, level+1});
            }
            if(cur->right){
                q.push({cur->right, level+1});
            }
        }

        for(vector<int>& layer : layers){
            for(int v : layer) cout<<v<<", ";
            cout<<endl;
        }

        for(int i = 0; i<layers.size(); i++){
            if(i & 1){ // odd
                for(int j = 1; j<layers[i].size(); j++){
                    if(layers[i][j-1] <= layers[i][j]) return false;
                }
            }
            else{ // even
                for(int j = 1; j<layers[i].size(); j++){
                    if(layers[i][j-1] >= layers[i][j]) return false;
                }
            }
        }

        return true;
    }
};

/*
BFS 해서 
쉽게쉽게 풀자
*/