// 3ms 초안
class Solution {
public:
    void DFS(TreeNode* v){
        if(v == NULL) return;
        if(v->left == NULL && v->right == NULL) return;

        TreeNode* temp = v->left;
        v->left = v->right;
        v->right = temp;
        
        DFS(v->left);
        DFS(v->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        DFS(root);
        return root;  
    }
};

// 굳이 함수 안 만들고 풀 수도 있다. 아래와 같이 묶어버리면 된다.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;  
    }
};