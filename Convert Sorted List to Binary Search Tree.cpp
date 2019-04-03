/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    TreeNode *sortedListToBST(ListNode *head)
    {

        if (!head)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);

        ListNode *slow = head;
        ListNode *prev = head;
        ListNode *fast = head;
        TreeNode *root = new TreeNode(0);
        // find sub-list's mid point
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL; // cut left sub-list

        root->val = slow->val;
        root->right = sortedListToBST(slow->next);
        root->left = sortedListToBST(head);

        return root;
    }
};