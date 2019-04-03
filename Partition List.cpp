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
    ListNode* partition(ListNode* head, int x) {
        ListNode* queue1 = new ListNode(0);
        ListNode* queue2 = new ListNode(0);
        ListNode* cur1 = queue1;
        ListNode* cur2 = queue2;
        while(head){
            if(head->val < x){
                cur1->next = head;
                head = head->next;
                cur1 = cur1->next;
            }else{
                cur2->next = head;
                head = head->next;
                cur2 = cur2->next;
            }
        }
        cur1->next = queue2->next;
        cur2->next = NULL;
        return queue1->next;
    }
};