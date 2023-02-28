// Runtime 31 ms Beats 67.8%
// Memory 49.6 MB Beats 32%

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
class Solution {
public:
    unordered_map<string, int> m;
    vector<TreeNode*> answer;
    string preorder(TreeNode* v){
        if(v == NULL) return "";
        string childsTraverseResult = to_string(v->val);
        childsTraverseResult += "L" + preorder(v->left);
        childsTraverseResult += "R" + preorder(v->right);

        m[childsTraverseResult]++;
        if(m[childsTraverseResult] == 2){
            answer.push_back(v);
        }
        return childsTraverseResult;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return answer;
    }
};

/*
leaf부터 보자. (base case)
leaf value가 같으면 duplicate이다.

올라오는 게 없으니까, 내려가는 걸로 해야 할 듯
DFS 했을 때, 같은 substring이 있

1
 - 2 - 4
 - 3 - 2 - 4
     - 4
largest duplicate를 찾으면, 그 size만큼 내려가면서 duplicate 넣을 수 있음. - 중복될 수도 잇기 때문에 set이 맞나?
1 - 2 - 4 - 3 - 2 - 4 - 4

어떤 점부터 traverse 결과를 string으로 map에 넣어두면 그 순회 결과가 몇개인지 셀수 있음

traverse할 때, self로 돌아왔을 때, 순회 결과를 map에 string으로 넣음. map<string, TreeNode*>
만약 이미 있는 거다 ? 그러면 map에 있는 value를 header set에 넣음.
preorder로 해야 하고

DFS는 O(n), 각 DFS에서 map에 삽입, logn
O(nlogn)

*/