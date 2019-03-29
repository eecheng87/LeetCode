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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cur1 = headA;
        ListNode *cur2 = headB;
        int alen = 0;
        int blen = 0;
        while (cur1 != NULL || cur2 != NULL)
        {
            if (cur1 != NULL)
            {
                alen++;
                cur1 = cur1->next;
            }
            if (cur2 != NULL)
            {
                blen++;
                cur2 = cur2->next;
            }
        }

        cur1 = headA;
        cur2 = headB;
        if (alen >= blen)
        {
            while (alen != blen)
            {
                alen--;
                cur1 = cur1->next;
            }
        }
        else
        {
            while (alen != blen)
            {
                blen--;
                cur2 = cur2->next;
            }
        }
        while (cur1 != NULL && cur2 != NULL)
        {
            if (cur1 == cur2)
                break;
            else
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }

        if (cur1 == NULL || cur2 == NULL)
            return NULL;
        return cur1;
    }
};