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
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> hash;
        while (head != NULL)
        {
            if (hash.find(head) == hash.end())
            {
                hash.insert({head, 1});
            }
            else
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};