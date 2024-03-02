/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // init
        int len = 1;
        ListNode *cur;
        
        // get total length
        cur = head;
        while(cur->next){
            cur = cur->next;
            len++;
        }

        // n-1번째 node를 찾아야 함.
        // n-1번째 node와 n+1번째 node를 합쳐야 함.

        // 1 <= n <= sz이므로
        if(n == len){
            if(len > 1) return head->next;
            else return NULL; // size 1일 때 없애는 경우
        }

        // 나머지는 모두 처리 가능
        // 제일 뒤의 것일 때 : n = 1, len = len - 2
        cur = head;
        len -= n+1; // 
        while(len--){
            cur = cur->next;
        }

        if(cur->next) cur->next = cur->next->next;

        return head;
    }
};