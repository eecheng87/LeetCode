/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        vector<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            if(cur->right)
                q.push_back(cur->right);
            if(cur->left)
                q.push_back(cur->left);
            ans = q.front()->val;
            q.erase(q.begin());
        }
        return ans;
    }
};