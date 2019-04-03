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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cur = 1;
        ListNode* tmp;
        ListNode* flag = head;
        ListNode* start;
        ListNode* end;
        ListNode* preStart = NULL;
        ListNode* endNext = NULL;
        
        // set variable to right position
        while(cur < n+2 ){
            if(cur == m-1)
                preStart = flag;
            if(cur == m)
                start = flag;
            if(cur == n)
                end = flag;
            if(cur == n+1)
                endNext = flag;
            if(flag)
                flag = flag->next;    
            cur++;
        }
      
        // start to reverse particular sub-list
        ListNode* A;
        ListNode* B = NULL;
        ListNode* C = start;
        while(C != endNext){
            A = C;
            C = C->next;
            A->next = B;
            B = A;
        }
       
        // reconstruct list
        if(!preStart){
            start->next = endNext;
            return end;
        }
        
        preStart->next = end;
        start->next = endNext;
        
        return head;
    }
};