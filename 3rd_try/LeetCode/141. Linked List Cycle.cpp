/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        unordered_map<ListNode*, bool> visited;

        visited[head] = true;
        while(head->next){
            head = head->next;
            if(visited[head]) return true;
            visited[head] = true;
        }
        return false;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;

        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) return true;
        }
        return false;
    }
};