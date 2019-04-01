/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (!head)
            return head;
        ListNode *dum = new ListNode(0);
        ListNode *prev = dum;
        dum->next = head;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast)
        {
            while (fast && slow && fast->val == slow->val)
            {
                while (fast->next && slow->val == fast->next->val)
                {
                    fast = fast->next;
                }
                prev->next = fast->next;
                slow = prev->next;
                if (slow)
                    fast = slow->next;
            }
            if (!fast || !slow)
                break;
            prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }

        return dum->next;
    }
};