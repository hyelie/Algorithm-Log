// Runtime 0 ms Beatse 100%
// Memory 10.6 MB Beats 29.89%

class Solution {
public:
    vector<TreeNode*> arr;
    // isPreviousComplete : 이전 단계가 incomplete
    bool fillarr(bool isPreviousIncomplete){
        // null 이후에 notnull이 오는지 + 현 layer 탐색
        vector<TreeNode*> curarr;
        bool hasNull = false;
        for(TreeNode* t : arr){
            if(t->left){
                if(hasNull) return false;
                curarr.push_back(t->left);
            }
            else hasNull = true;
            if(t->right){
                if(hasNull) return false;
                curarr.push_back(t->right);      
            }
            else hasNull = true;
        }

        if(curarr.size() == 0) return true; // 1번 조건
        if(isPreviousIncomplete && curarr.size() >= 1) return false; // 2번 조건
        if(curarr.size() != arr.size() * 2) isPreviousIncomplete = true; // 3번 조건
        arr = curarr;
        return fillarr(isPreviousIncomplete);
    }
    bool isCompleteTree(TreeNode* root) {
        arr.push_back(root);
        return fillarr(false);
    }
};