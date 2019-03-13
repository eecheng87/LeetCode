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
    bool isBalanced(TreeNode *root)
    {

        if (!root)
            return true;

        bool ans = true;

        int right = help(root->right, &ans);
        int left = help(root->left, &ans);
        int tmp = left > right ? left - right : right - left;
        if (tmp > 1)
            ans = false;

        return ans;
    }
    int help(TreeNode *root, bool *ans)
    {

        if (!root)
            return 0;

        int left = help(root->left, ans);
        int right = help(root->right, ans);

        int tmp = left > right ? left - right : right - left;
        if (tmp > 1)
            *ans = false;

        return left > right ? left + 1 : right + 1;
    }
};