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
    TreeNode* solve(TreeNode * a,TreeNode *b){
        
        if(!a)return b;
        if(!b)return a;
        
        a->val+=b->val;
        a->left=solve(a->left,b->left);
        a->right=solve(a->right,b->right);
        return a;
        
            
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        solve(root1,root2);
        return root1;
    }
};