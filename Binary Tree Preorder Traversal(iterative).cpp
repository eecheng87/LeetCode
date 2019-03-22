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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        vector<TreeNode *> stack;
        if (root)
            stack.push_back(root);
        while (!stack.empty())
        {
            TreeNode *tmp = stack.back();
            stack.pop_back();
            ans.push_back(tmp->val);
            if (tmp->right)
                stack.push_back(tmp->right);
            if (tmp->left)
                stack.push_back(tmp->left);
            // becareful that line 21 and 23 can't switch!!
        }
        return ans;
    }
};