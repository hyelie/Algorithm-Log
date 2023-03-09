/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 a=c
 t % l, 2t % l 만나는 지점 -> t=l일 때. 
 2a = (a + l)
 a = l

딱알았다 두 vertex가 같을 때, 거기가 시작 위치임.
https://leetcode.com/problems/linked-list-cycle-ii/solutions/3274442/c-best-approach-with-fully-explained-naive-to-optimised/

cycle이 없다면 fast는 진행 중 null을 만남.
cycle이 있다면 fast는 slow보다 항상 빠르기 때문에 k바퀴를 돌고 따라잡게 됨.
그래서 2(a + b) = a + b + k(c + b)가 성립한다.
a = (k-1)b + kc. k가 1이면 kc.
fast가 1바퀴 돌고 만나면 a=c
즉 slow가 a만큼 갈떄 fast는 2a만큼 감. = a + c.
이 때 a만큼 더 가주면 거기가 시작점.
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(1){
            if(fast == NULL || fast->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
            // 만났다면 fast를 a만큼 보내야 함
            if(fast == slow){
                while(head != fast){
                    head = head->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};