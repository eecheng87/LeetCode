/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        help(root,ans);
        return ans;
    }
    void help(TreeNode* root,vector<int> &ans){
        if(root){
            ans.push_back(root->val);
            help(root->left,ans);
            help(root->right,ans);
        }
    }
};