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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode emp(0);
        ListNode *dummy = &emp;
        ListNode *tail;
        ListNode *tmp;

        dummy->next = NULL;
        tail = dummy;
        while (l1 != NULL & l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                tmp = l2;
                l2 = l2->next;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tmp;
            }
            else
            {
                tmp = l1;
                l1 = l1->next;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tmp;
            }
        }

        if (l1 == NULL)
            tail->next = l2;
        else
            tail->next = l1;

        return dummy->next;
    }
};