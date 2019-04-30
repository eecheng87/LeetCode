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
    int kthSmallest(TreeNode *root, int k)
    {

        int cur = 1;
        int ans;
        help(root, k, cur, ans);
        return ans;
    }
    void help(TreeNode *root, int k, int &cur, int &ans)
    {
        if (root == NULL)
            return;
        else
        {
            help(root->left, k, cur, ans);
            if (k == cur)
            {
                ans = root->val;
                cur++;
            }
            else
            {
                cur++;
            }
            help(root->right, k, cur, ans);
        }
    }
};