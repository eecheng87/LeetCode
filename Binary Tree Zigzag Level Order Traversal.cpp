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
    vector<vector<int>> ans;
    void dfs(TreeNode* node, int dep){
        if(!node)return;
        vector<int> tmp;
        if(ans.size() <= dep){
            tmp.push_back(node->val);
            ans.push_back(tmp);
        }else{
            if(dep%2==0){
                ans[dep].push_back(node->val);
            }else{
                ans[dep].insert(ans[dep].begin(), node->val);
            }
        }
        
        dfs(node->left, dep + 1);
        dfs(node->right, dep + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root)return ans;
        dfs(root, 0);
        return ans;
    }
};




