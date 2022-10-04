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
    TreeNode * ans;
    void solve(TreeNode* a,TreeNode* b,TreeNode* t){
        if(!a)
            return ;
        
        solve(a->left,b->left,t);
        if(a == t)
            ans=b;
        solve(a->right,b->right,t);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        solve(original,cloned,target);
        return ans;
    }
};