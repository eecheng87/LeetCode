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
    int getMinimumDifference(TreeNode *root)
    {
        int ans = 100000;
        vector<int> list;
        read(root, list);
        for (int i = 1; i < list.size(); i++)
        {
            int delta = (list[i] - list[i - 1]) > 0 ? (list[i] - list[i - 1]) : -(list[i] - list[i - 1]);
            ans = (delta < ans) ? delta : ans;
        }
        return ans;
    }
    void read(TreeNode *root, vector<int> &list)
    {
        if (root == NULL)
            return;
        else
        {
            read(root->left, list);
            list.push_back(root->val);
            read(root->right, list);
        }
    }
};