/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        
        //go right
        if(p->val>r->val and q->val>r->val)
            return lowestCommonAncestor(r->right,p,q);
        //go left
        else if(p->val<r->val and q->val<r->val)
            return lowestCommonAncestor(r->left,p,q);
        return r;
    }
};