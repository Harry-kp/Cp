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
    TreeNode* pruneTree(TreeNode* r) {
        if(!r)return NULL;
        
        if(!r->left and !r->right and r->val == 0)
            return NULL;
        
        r->left = pruneTree(r->left);
        r->right=pruneTree(r->right);
        
        if(!r->left and !r->right and r->val == 0)
            return NULL;
        
        return r;
    }
};