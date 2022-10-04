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
    void solve(TreeNode* root,int& ans){
        static int prev=100000;
        
        if(!root)return;
        solve(root->left,ans);
        int tmp = abs(prev-root->val);
        prev = root->val;
        ans = min(ans,tmp);
        solve(root->right,ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = 1000000;
        
        solve(root,ans);
        return ans;
    }
};