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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        deque<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> level;
        TreeNode *head;
        TreeNode *left;
        TreeNode *right;

        q.push_back(root);

        int num = 1;
        int null = 0;
        int offset = 0;

        while (!q.empty() && !(null == num + offset))
        {
            null = 0;
            offset = 0;
            for (int i = 0; i < num; i++)
            {
                head = q[0];
                q.pop_front();
                if (head)
                {
                    level.push_back(head->val);
                    left = head->left;
                    right = head->right;
                    q.push_back(left);
                    q.push_back(right);
                }
                else
                {
                    // null
                    //q.push_back(NULL);
                    //q.push_back(NULL);
                    null += 2;
                    offset += 2;
                }
            }
            if (!level.empty())
            {
                ans.push_back(level);
                level.clear();
            }
            num *= 2;
            num -= offset;
        }

        return ans;
    }
};