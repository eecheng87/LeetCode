/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    deque<TreeNode*>stack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* tmp = root;
        while(tmp){
            stack.push_back(tmp);
            tmp=tmp->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ans=stack.back();
        stack.pop_back();
        TreeNode* tmp=ans;
        if(tmp->right){
            tmp=tmp->right;
            stack.push_back(tmp);
            tmp=tmp->left;
            while(tmp){
                stack.push_back(tmp);
                tmp=tmp->left;
            }
        }
        
        return ans->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stack.empty()?false:true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */