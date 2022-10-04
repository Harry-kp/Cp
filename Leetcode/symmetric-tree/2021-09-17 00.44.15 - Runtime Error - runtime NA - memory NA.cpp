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
    
    bool same(TreeNode * root1,TreeNode * root2){
        if(root1->left == NULL and root2->right == NULL)
            return true;
        
        if((root1->left == NULL)  +  (root2->right == NULL) == 1)
            return false;
        
        return root1->val == root2->val and same(root1->left,root2->right) and same(root1->right,root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        
        return same(root->left,root->right);
    }
};