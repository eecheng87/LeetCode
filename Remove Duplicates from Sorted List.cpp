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
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != NULL)
        {
            if (fast->val == slow->val)
            {
                slow->next = fast->next;
                fast = slow->next;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return head;
    }
};