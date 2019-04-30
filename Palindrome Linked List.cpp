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
    bool isPalindrome(ListNode* head) {
        ListNode* cur=head;
        bool ans=true;
        vector<int> list;
        while(cur){
            list.push_back(cur->val);
            cur = cur->next;
        }
        int i=0;
        int j=list.size()-1;
        if(list.size()%2==0){
            //even
            while(i<j){
                if(list[i]!=list[j]){
                    ans = false;
                    break;
                }else{
                    i++;
                    j--;
                }
            }
        }else{
            // odd
            while(i!=j){
                if(list[i]!=list[j]){
                    ans = false;
                    break;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};