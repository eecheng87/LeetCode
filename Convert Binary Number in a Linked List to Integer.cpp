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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head){
            if(head->val > 0){
                ans += 1;
            }
            //cout<<ans<<endl;
            ans = ans<<1;
            head = head->next;
        }
            
        return ans>>1;
    }
};