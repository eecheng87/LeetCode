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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> queue;
        int curRowExp=0;
        int curRowNum;
        int index=0;
        int nextIndex=0;
        int last;
        vector<int> ans;
        if(root)
            queue.push_back(root);
        while(!queue.empty()){
            
            TreeNode* tmp = queue.front();
            queue.pop_front();
            last = tmp->val;
            
            if(tmp->left!=NULL)
                queue.push_back(tmp->left);
            else
                nextIndex+=1;
            
            if(tmp->right!=NULL)
                queue.push_back(tmp->right);
            else
                nextIndex+=1;
            
            index++;
         
            // change row test
            if(index == pow(2,curRowExp)){
                curRowExp++;
                index = nextIndex;
                nextIndex = 2*nextIndex;
                ans.push_back(last);
            }
            
        }
        return ans;
    }
};