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
    void solve(TreeNode* root,int& prev,int& ans){
        if(!root)return;
        solve(root->left,root->val,ans);
        int tmp = abs(prev-root->val);
        ans = min(ans,tmp);
        solve(root->right,root->val,ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = 1000000;
        int prev = 100000;
        
        solve(root,prev,ans);
        return ans;
    }
};