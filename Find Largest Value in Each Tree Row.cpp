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
    void pre(TreeNode* node, int dep, vector<int> &ans){
        if(!node)return;
        
        if(ans.size() <= dep){
            ans.push_back(node->val);
        }else{
            ans[dep] = max(ans[dep], node->val);
        }
        
        pre(node->left, dep+1, ans);
        pre(node->right, dep+1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        pre(root, 0, ans);
        return ans;
    }
};