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
    vector<vector<int>> ans;
    int gls;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        gls = sum;
        traverse(path,root,0);
        return ans;
    }
    void traverse(vector<int> &path,TreeNode* root,int curs){
        if(!root)
            return;
        path.push_back(root->val);
        if(root->val + curs == gls && !root->left && !root->right){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        curs += root->val;
        traverse(path,root->left,curs);
        traverse(path,root->right,curs);
        path.pop_back();
    }
};