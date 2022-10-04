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
    void solve(TreeNode* r,int& pre,int& mn){
        if(!r)
            return ;
        
        
        solve(r->left,pre,mn);
        mn = min(mn,r->val-pre);
        pre = r->val;
        solve(r->right,pre,mn);
            
    }
    int minDiffInBST(TreeNode* root) {
        int res = 10000;
        int pre = -10000;
        solve(root,pre,res);
        return res;
    }
};