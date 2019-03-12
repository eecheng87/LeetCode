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
        deque<TreeNode *> stack;
        TreeNode *tmp = root;

        while (!stack.empty() || tmp)
        {
            while (tmp)
            {
                stack.push_back(tmp);
                tmp = tmp->left;
            }
            tmp = stack.back();
            ans.push_back(tmp->val);
            stack.pop_back();
            tmp = tmp->right;
        }

        return ans;
    }
};