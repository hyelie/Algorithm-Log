// Runtime 5 ms Beats 52.61% 
// Memory 10.3 MB Beats 21.22%

/*
x보다 작은 entry들은 다른 linked list로 옮기고, x보다 큰 entry들은 그대로 둠.
- start pointer를 하나 두고, x보다 작은 것은 다 start로 옮김. x 이상인 것은 순서를 유지한 채로 head에 있을 것임.

이후 start와 원래 head를 이어붙임.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* start = new ListNode();
        ListNode* end = start;

        // 제일 처음 것도 옮기기 위해 새로운 head temp를 둠
        ListNode* temp = new ListNode(101, head);
        head = temp;
        ListNode* cur = head->next, *prev = head;
        while(1){
            cur = prev->next;
            if(cur == NULL) break;
            if(cur->val < x){
                // 원래 것에서 뺌
                prev->next = cur->next;

                // 새로운 partition에 추가
                end->next = cur;
                cur->next = NULL;
                end = cur;
            }
            else{
                prev = prev->next;
                if(prev == NULL) break;
            }
        }
        head = temp->next;
        
        if(start->next == NULL) return head;
        start = start->next;
        end->next = head;
        return start;
    }
};

// Runtime 8 ms Beats 38.42%
// Memory 10.2 MB Beats 48.14%

/*
x보다 작은 entry들은 less에 옮기고, x보다 큰 entry들은 ge에 옮김.
이수 less와 ge를 이어붙임.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode();
        ListNode* less_end = less;
        ListNode* ge = new ListNode();
        ListNode* ge_end = ge;

        while(head != NULL){
            if(head->val < x){ // less에 붙여넣음
                less_end->next = head;
                less_end = head;
            }
            else{
                ge_end->next = head;
                ge_end = head;
            }

            head = head->next;
        }

        // remove dummy & connect
        ge = ge->next;
        less_end->next = ge;
        less = less->next;
        ge_end->next = NULL;
        return less;
    }
};