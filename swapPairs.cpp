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
    ListNode *swapPairs(ListNode *head)
    {

        if (head == NULL)
            return NULL;

        ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *first = head;
        ListNode *second = head->next;

        while (first != NULL && second != NULL)
        {
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            first = first->next;
            if (first == NULL)
                break;
            second = first->next;
        }
        return dummy->next;
    }
};