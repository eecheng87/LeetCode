class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {
        // situation NULL or one node
        if (!head || !head->next)
            return head;

        // start to find mid
        ListNode *front = head;
        ListNode *tail = head->next;
        while (tail && tail->next)
        {
            front = front->next;
            tail = tail->next->next;
        }
        ListNode *newHead = front->next;
        front->next = NULL;

        return merge(sortList(head), sortList(newHead));
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *result = (ListNode *)malloc(sizeof(ListNode));
        ListNode *cur = result;
        while (a && b)
        {
            if (a->val < b->val)
            {
                cur->next = a;
                a = a->next;
                cur = cur->next;
                cur->next = NULL;
            }
            else
            {
                cur->next = b;
                b = b->next;
                cur = cur->next;
                cur->next = NULL;
            }
        }

        if (!a)
        {
            cur->next = b;
        }
        else
        {
            cur->next = a;
        }

        return result->next;
    }
};