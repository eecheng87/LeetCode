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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        int len = 0;
        ListNode *cur = root;
        ListNode *flag, *head;

        while (cur)
        {
            cur = cur->next;
            len++;
        }

        cur = root;
        int seg = len % k;

        vector<int> index(k, len / k);
        vector<ListNode *> ans(k);

        for (int i = 0; seg > 0; i++)
        {
            index[i]++;
            seg--;
        }

        for (int i = 0; i < k; i++)
        {
            if (index[i] == 0)
            {
                continue;
            }
            head = ans[i] = cur;
            cur = cur->next;
            index[i]--;
            while (index[i] > 0)
            {
                head->next = cur;
                head = head->next;
                cur = cur->next;
                index[i]--;
            }
            head->next = NULL;
        }

        return ans;
    }
}; /**
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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        int len = 0;
        ListNode *cur = root;
        ListNode *flag, *head;

        while (cur)
        {
            cur = cur->next;
            len++;
        }

        cur = root;
        int seg = len % k;

        vector<int> index(k, len / k);
        vector<ListNode *> ans(k);

        for (int i = 0; seg > 0; i++)
        {
            index[i]++;
            seg--;
        }

        for (int i = 0; i < k; i++)
        {
            if (index[i] == 0)
            {
                continue;
            }
            head = ans[i] = cur;
            cur = cur->next;
            index[i]--;
            while (index[i] > 0)
            {
                head->next = cur;
                head = head->next;
                cur = cur->next;
                index[i]--;
            }
            head->next = NULL;
        }

