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
    bool solve(TreeNode* r,const int& val){
        if(!r)
            return true;
        return r->val!=val?false:(solve(r->left,val)&solve(r->right,val));
    }
    
    bool isUnivalTree(TreeNode* r) {
        if(!r)return true;
        return solve(r,r->val);
    }
};