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
    
    string tree2str(TreeNode* r) {
        if(!r)
            return "";
        if(!r->left and !r->right)
            return to_string(r->val);
        if(!r->right)
            return to_string(r->val)+"(" + tree2str(r->left)+")";
        return to_string(r->val) + "(" + tree2str(r->left)+")(" +tree2str(r->right)+")";
    }
};