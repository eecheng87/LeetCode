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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *cur = head;
        ListNode *flag;
        ListNode *tmp;

        while (n > 0)
        {
            n--;
            cur = cur->next;
        }

        flag = head;

        if (cur == NULL)
            return head->next;
        while (cur->next != NULL)
        {
            cur = cur->next;
            flag = flag->next;
        }

        tmp = flag->next;
        if (tmp == NULL)
            return NULL;
        else
            flag->next = tmp->next;

        return head;
    }
};