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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* cur = head;
        ListNode* odd_cur = odd;
        ListNode* even_cur = even;
        int flag = 0;
        while(cur){
            if(flag==0){
                odd_cur->next = cur;
                odd_cur = odd_cur->next;
                flag = 1;
            }else{
                even_cur->next = cur;
                even_cur = even_cur->next;
                flag = 0;
            }
            cur = cur->next;
            //cout<<cur->val;
        }
        even_cur->next = NULL;
        odd_cur->next = even->next;
        return odd->next;
    }
};