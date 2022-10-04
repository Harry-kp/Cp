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
    bool same(TreeNode * a,TreeNode * b){
        if(!a and !b)return true;
        
        if(a and b)
            return a->val == b->val and same(a->left,b->right) and same(a->right,b->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return same(root->left,root->right);
    }
};