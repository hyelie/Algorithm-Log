// Runtime 12 ms Beats 92.40%
// Memory 26.5 MB Beats 48.48%

class Solution {
public:
    vector<int> inorder, postorder;
    unordered_map<int, int> inorder_idx;
    TreeNode* build(int inorder_start, int inorder_end, int postorder_start, int postorder_end){
        if(inorder_start > inorder_end || postorder_start > postorder_end) return NULL;

        int inorder_rootidx = inorder_idx[postorder[postorder_end]];
        // for(int i = inorder_start; i<=inorder_end; i++){
        //     if(postorder[postorder_end] == inorder[i]){
        //         inorder_rootidx = i;
        //         break;
        //     }
        // }

        if(inorder_rootidx == -1) return NULL;

        TreeNode* curroot = new TreeNode(postorder[postorder_end]);
        int leftlen = inorder_rootidx - inorder_start;
        int rightlen = inorder_end - inorder_rootidx;

        curroot->left = build(inorder_start, inorder_rootidx-1, postorder_start, postorder_start + leftlen - 1);
        curroot->right = build(inorder_rootidx+1, inorder_end, postorder_start + leftlen, postorder_end - 1);

        return curroot;
    }
    TreeNode* buildTree(vector<int>& _inorder, vector<int>& _postorder) {
        inorder = _inorder; postorder = _postorder;
        for(int i = 0; i<inorder.size(); i++){
            inorder_idx[inorder[i]] = i;
        }
        return build(0, _inorder.size()-1, 0, _postorder.size()-1);
    }
};