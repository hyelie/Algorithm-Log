// Runtime 16 ms Beats 75.53%
// Memory 16.1 MB Beats 56.82%

class Solution {
public:
    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(NULL);
            return result;
        }

        for(int i = start; i<=end; i++){
            vector<TreeNode*> left = build(start, i-1);
            vector<TreeNode*> right = build(i+1, end);

            for(int j = 0; j<left.size(); j++){
                for(int k = 0; k<right.size(); k++){
                    TreeNode* parent = new TreeNode(i);
                    parent->left = left[j];
                    parent->right = right[k];
                    result.push_back(parent);
                }
            }
        }

        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};