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
    void flatten(TreeNode *root)
    {
        help(root);
    }

    void help(TreeNode *prev)
    {
        if (!prev)
            return;
        help(prev->left);
        help(prev->right);
        if (!prev->left)
            return;
        if (!prev->left->left)
        {
            TreeNode *last = prev;
            TreeNode *rightHead = prev->right;
            TreeNode *leftLast = prev->left;

            while (leftLast->right)
            {
                leftLast = leftLast->right;
            }

            prev->right = prev->left;
            prev->left = NULL;
            leftLast->right = rightHead;

            return;
        }
    }
};