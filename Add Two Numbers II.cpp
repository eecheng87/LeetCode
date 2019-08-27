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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0), *ll1 = l1, *ll2 = l2, *cur;
        vector<int> l1v;
        vector<int> l2v;
        vector<int> ansv;
        int carry = 0;
        while (ll1)
        {
            l1v.push_back(ll1->val);
            ll1 = ll1->next;
        }
        while (ll2)
        {
            l2v.push_back(ll2->val);
            ll2 = ll2->next;
        }

        int i = l1v.size() - 1;
        int j = l2v.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--)
        {
            ansv.insert(ansv.begin(), (l1v[i] + l2v[j] + carry) % 10);
            carry = (l1v[i] + l2v[j] + carry) / 10;
        }

        if (i > j)
        {
            for (int k = i; k >= 0; k--)
            {
                ansv.insert(ansv.begin(), (l1v[k] + carry) % 10);
                carry = (l1v[k] + carry) / 10;
            }
        }
        else if (i < j)
        {
            for (int k = j; k >= 0; k--)
            {
                ansv.insert(ansv.begin(), (l2v[k] + carry) % 10);
                carry = (l2v[k] + carry) / 10;
            }
        }

        if (carry == 1)
            ansv.insert(ansv.begin(), 1);
        cur = ans;

        for (int i = 0; i < ansv.size(); i++)
        {
            cur->next = new ListNode(ansv[i]);
            cur = cur->next;
        }
        cur->next = NULL;
        return ans->next;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0), *ll1 = l1, *ll2 = l2, *cur;
        vector<int> l1v;
        vector<int> l2v;
        vector<int> ansv;
        int carry = 0;
        while (ll1)
        {
            l1v.push_back(ll1->val);
            ll1 = ll1->next;
        }
        while (ll2)
        {
            l2v.push_back(ll2->val);
            ll2 = ll2->next;
        }

        int i = l1v.size() - 1;
        int j = l2v.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--)
        {
            ansv.insert(ansv.begin(), (l1v[i] + l2v[j] + carry) % 10);
            carry = (l1v[i] + l2v[j] + carry) / 10;
        }

        if (i > j)
        {
            for (int k = i; k >= 0; k--)
            {
                ansv.insert(ansv.begin(), (l1v[k] + carry) % 10);
                carry = (l1v[k] + carry) / 10;
            }
        }
        else if (i < j)
        {
            for (int k = j; k >= 0; k--)
            {
                ansv.insert(ansv.begin(), (l2v[k] + carry) % 10);
                carry = (l2v[k] + carry) / 10;
            }
        }

        if (carry == 1)
            ansv.insert(ansv.begin(), 1);
        cur = ans;

        for (int i = 0; i < ansv.size(); i++)
        {
