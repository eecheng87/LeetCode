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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* dum = new ListNode(0);
        ListNode* fast = head;
        ListNode* mid = head;
        ListNode* flag = dum;
        dum->next = head;
        while(fast && fast->next){
            flag = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        if(!fast)
            flag->next = NULL;
        // reverse node after mid ( include )
        ListNode* prev = NULL;
        ListNode* cur = mid;
        ListNode* precede = mid->next;
        // mid->next = NULL;
        while(precede){
            cur->next = prev;
            prev = cur;
            cur = precede;
            precede = precede->next;
        }
        cur->next = prev;
        mid = cur;
        
        
        // reorder
        ListNode* n1;
        ListNode* n2;
        fast = head;
        while(fast && mid){
            n1 = fast;
            n2 = mid;
            fast = fast->next;
            mid = mid->next;
            n1->next = n2;
            n2->next = fast;
        }
        /*if(fast)
            n2->next = fast;
        if(mid)
            n1->next = mid;*/
        
    }
};