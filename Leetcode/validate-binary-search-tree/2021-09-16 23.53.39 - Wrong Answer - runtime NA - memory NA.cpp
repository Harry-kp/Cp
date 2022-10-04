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
    //if bst is valid then inorder traversal is sorted . Hence , we traverse bst in inorder way and keep track of previous visited node
    
    bool valid(TreeNode * root,TreeNode * prev){
        
        if(root!=NULL){
            
            if(!valid(root->left,prev));
            
            if(prev!=NULL and prev->val>=root->val)
                    return false;
            prev = root;
            return valid(root->right,prev);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL;
        
        return valid(root,prev);
        
    }
};