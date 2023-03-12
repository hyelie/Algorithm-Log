// Runtime 27 ms Beats 60.37%
// Memory 13.3 MB Beats 58.2%

struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(ListNode* v : lists){
            if(v != NULL) pq.push(v);
        }

        ListNode* head;
        ListNode *iter = new ListNode();
        head = iter;
        
        while(!pq.empty()){
            ListNode* top = pq.top(); pq.pop();
            // if(top != NULL){ // pq에는 NULL이 없음
                iter->next = top;
                iter = iter->next;
                if(top->next != NULL) pq.push(top->next);
            // }       
        }

        return head->next;
    }
};