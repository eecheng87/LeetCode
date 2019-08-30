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
    vector<int> nextLargerNodes(ListNode *head)
    {

        vector<int> arr;
        vector<int> stack;

        ListNode *cur = head;
        while (cur)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        vector<int> ans(arr.size(), 0);

        cur = head;

        for (int i = arr.size() - 1; i >= 0; i--)
        {

            while (!stack.empty() && stack.back() <= arr[i])
            {
                stack.pop_back();
            }
            ans[i] = stack.empty() ? 0 : stack.back();
            stack.push_back(arr[i]);
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
    vector<int> nextLargerNodes(ListNode *head)
    {

        vector<int> arr;
        vector<int> stack;

        ListNode *cur = head;
        while (cur)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        vector<int> ans(arr.size(), 0);

        cur = head;

        for (int i = arr.size() - 1; i >= 0; i--)
        {

            while (!stack.empty() && stack.back() <= arr[i])
            {
                stack.pop_back();
            }
            ans[i] = stack.empty() ? 0 : stack.back();
            stack.push_back(arr[i]);
        }

