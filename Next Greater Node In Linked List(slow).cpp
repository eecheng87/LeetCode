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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* cur = head,*tmp;
        int t, max = -1;
        bool zero = true;
        while(cur->next){
            tmp = cur;
       
            while(tmp){
                if(tmp->val>cur->val){
                    max = tmp->val;
                    zero = false;
                    break;
                }
                tmp = tmp->next;
            }
            ans.push_back(zero?0:max);
            cur = cur->next;
            max = -1;
            zero = true;
        }
        ans.push_back(0);
        return ans;
    }
};