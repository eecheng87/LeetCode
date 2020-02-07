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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* cur;
        ListNode* dum = new ListNode(0);
        dum->val = 0;
        dum->next = head;
        cur = dum;
        int sum = 0;
        unordered_map<int,ListNode*> mp;
        while(cur){
            sum += cur->val;
            if(mp.find(sum) != mp.end()){
                // have same sum
                int tmp_sum = sum;
                ListNode* tmp_p = mp[sum]->next;
                while(tmp_p && tmp_p != cur){
                    tmp_sum += tmp_p->val;
                    mp.erase(tmp_sum);
                    tmp_p = tmp_p->next;
                }
                //cout<<sum<<endl;
                mp[sum]->next = cur->next;
            }else{
                mp[sum] = cur;
            }
            cur = cur->next;
        }
        return dum->next;
    }
};