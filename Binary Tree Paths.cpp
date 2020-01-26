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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        dfs(ans,path,root);
        return ans;
    }
    void dfs(vector<string>&ans, string& path, TreeNode* root){
        
        if(!root)
            return;
        if(!root->left && !root->right){
            // leaf
            ans.push_back(path + to_string(root->val));
            return;
        }
        path += to_string(root->val) + "->";
        dfs(ans,path,root->left);
        dfs(ans,path,root->right);
        while(!path.empty() && path.back() != '-')
            path.pop_back();
        while(!path.empty() && path.back() != '>')
            path.pop_back();
    }
};