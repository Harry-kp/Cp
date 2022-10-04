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
        if(!r){
        // cout<<c<<'\n';
        ans+=c;
        return ;
    }
        
        solve(r->left,(c<<1)|r->val,ans);
        solve(r->right,(c<<1)|r->val,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root,0,ans);
        return ans/2;
    }
};