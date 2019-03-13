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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool ans = true;
        solve(p, q, &ans);
        return ans;
    }
    void solve(TreeNode *p, TreeNode *q, bool *ans)
    {
        if ((!p && q) || (!q && p))
            *ans = false;
        if (p && q)
        {
            if (p->val != q->val)
                *ans = false;
            solve(p->left, q->left, ans);
            solve(p->right, q->right, ans);
        }
    }
};