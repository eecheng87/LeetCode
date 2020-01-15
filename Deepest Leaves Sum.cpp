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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> queue;
        int prev;
        int ans = 0;
        if(!root)
            return 0;
        queue.push_back(root);
        while(!queue.empty()){
            for(int i = queue.size()-1,ans = 0; i >= 0; --i){
                if(queue[i]->left)
                    queue.push_back(queue[i]->left);
                if(queue[i]->right)
                    queue.push_back(queue[i]->right);
                ans += queue[i]->val;
                queue.erase(queue.begin()+i);
                prev = ans;
            }
        }
        return prev;
    }
};