
// Runtime 19 ms Beats 97.30%
// Memory 28.3 MB Beats 92.35%

class Solution {
public:
    ListNode *curNode; // curNode라는 변수가 middle pointer가 된다.
    int size = 0; // linked list size
    
    // attribute initialize
    void init(ListNode* head){
        this->curNode = head;
        while(head){
            head = head->next;
            this->size++;
        }
    }

    TreeNode* DFS(int start, int end){
        // base case. 범위가 벗어나지거나 curNode가 null인 경우 리턴
        if(start > end || this->curNode == NULL) return NULL;

        int mid = (start + end) / 2;
        
        // 1. left를 DFS한다.
        TreeNode *treeLeft = DFS(start, mid-1);

        // 2. curNode가 tree의 middle pointer가 된다. 따라서 curNode로 tree pointer를 만든다.
        TreeNode *treeMid = new TreeNode(curNode->val);
        
        // 3. curNode++한다.
        this->curNode = this->curNode->next;

        // 4. right를 DFS한다.
        TreeNode *treeRight = DFS(mid + 1, end);

        // 5. left, right DFS 결과를 tree middle에 붙여넣고 리턴한다.
        treeMid->left = treeLeft;
        treeMid->right = treeRight;

        return treeMid;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // base case
        if(head == NULL) return NULL;
        init(head);

        return DFS(0, this->size-1);
    }
};
