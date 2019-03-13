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
    ListNode *removeElements(ListNode *head, int val)
    {

        if (head == NULL)
            return NULL;

        while (head != NULL && head->val == val)
        {
            ListNode *TMP = head;
            head = head->next;
            free(TMP);
        }

        ListNode *tmp = head;
        ListNode *prev = (ListNode *)malloc(sizeof(ListNode));
        prev->next = head;

        while (tmp != NULL)
        {
            if (tmp->val == val)
            {
                //remove node
                prev->next = tmp->next;
                free(tmp);
                tmp = prev->next;
            }
            else
            {
                prev = prev->next;
                tmp = tmp->next;
            }
        }

        return head;
    }
};