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
    int ans = 0;
    void find(TreeNode* r, bool pre_right, bool state, int path){
        if(r){
            path++;
            /*if(!state){
                if(pre_right)
                    find(r->left,false,true,path);
                else
                    find(r->right,true,true,0);
                
            }else{
                if(pre_right)
                    find(r->left,false,true,path);
                else
                    find(r->right,true,true,0);
            }*/
            if(pre_right){
                find(r->left,false,true,path);
                find(r->right,true,true,0);
            }else{
                find(r->left,false,false,0);
                find(r->right,true,true,path);
            }
        }
        
        ans = ans > path ? ans : path;
    }
    int longestZigZag(TreeNode* root) {
        find(root->right,true,true,0);
        find(root->left,false,true,0);
        return ans;
    }
};