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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        priority_queue<int> pq;
        ListNode *cur;
        ListNode *prev;
        for (int i = 0; i < lists.size(); i++)
        {
            cur = lists[i];
            while (cur)
            {
                pq.push(cur->val);
                cur = cur->next;
            }
        }

        ListNode *ans = (ListNode *)malloc(sizeof(ListNode));
        ans->next = NULL;

        while (!pq.empty())
        {
            cur = (ListNode *)malloc(sizeof(ListNode));
            ans->val = pq.top();
            cur->next = ans;
            ans = cur;
            pq.pop();
        }

        return cur ? cur->next : NULL;
    }
};