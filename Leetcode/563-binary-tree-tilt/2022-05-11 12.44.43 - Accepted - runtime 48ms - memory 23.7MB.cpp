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
    int solve(TreeNode* r,int& ans){
        if(!r)return 0;
        
        int a = solve(r->left,ans);
        int b = solve(r->right,ans);
        
        ans+=abs(a-b);
        return a+b+r->val;;
        
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};