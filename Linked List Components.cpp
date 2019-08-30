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
    int numComponents(ListNode *head, vector<int> &G)
    {
        unordered_set<int> set(G.begin(), G.end());
        int ans = 0;
        bool found = false;
        while (head)
        {
            if (set.count(head->val) > 0)
            {
                if (!found)
                {
                    found = true;
                    ans++;
                }
            }
            else
            {
                found = false;
            }
            head = head->next;
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
    int numComponents(ListNode *head, vector<int> &G)
    {
        unordered_set<int> set(G.begin(), G.end());
        int ans = 0;
        bool found = false;
        while (head)
        {
            if (set.count(head->val) > 0)
            {
                if (!found)
                {
                    found = true;
                    ans++;
                }
            }
            else
            {
