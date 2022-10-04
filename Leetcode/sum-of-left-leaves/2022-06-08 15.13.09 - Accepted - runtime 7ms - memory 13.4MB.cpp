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
    int solve(TreeNode*r ,bool l){
        if(!r)return 0;
        if(!r->left and !r->right and l)
            return r->val;
        
        return solve(r->left,true)+solve(r->right,false);}
    int sumOfLeftLeaves(TreeNode* r) {
        return solve(r,false);
    }
};