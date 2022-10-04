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
    void solve(TreeNode * r,int c,int& ans){
        
    //check if leaf node
    if(!r->left and !r->right)
    {
        ans+=c;
        return;
    }
    if(r->left)
        solve(r->left,(c<<1)|(r->left->val),ans);
    if(r->right)
        solve(r->right,(c<<1)|(r->right->val),ans);
    
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root,root->val,ans);
        return ans;
    }
};