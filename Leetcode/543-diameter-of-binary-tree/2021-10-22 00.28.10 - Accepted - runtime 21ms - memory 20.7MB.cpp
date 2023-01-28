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
    int dia(TreeNode* root,int& height){
        if(root == NULL){
            height = 0;
            return 0;
        }
        int lh = 0;
        int rh = 0;
        
        int ld = dia(root->left,lh);
        int rd = dia(root->right,rh);
        
        height = max(lh,rh)+1;
        
        return max(max(ld,rd),lh+rh+1);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return dia(root,height)-1;
    }
};