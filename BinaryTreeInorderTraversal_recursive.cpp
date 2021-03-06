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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        help(root, ans);
        return ans;
    }
    void help(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        help(root->left, ans);
        ans.push_back(root->val);
        help(root->right, ans);
    }
};