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
    int depth(TreeNode* r){
        return r==NULL ? 0 : 1+depth(r->left);
    }

    int countNodes(TreeNode* r, int c=0) {
        if(r==NULL){
            return c;
        }

        int lh = depth(r->left);
        int rh = depth(r->right);

        return (lh == rh) ?  countNodes(r->right, c+(1<<lh)) :  countNodes(r->left, c+(1<<rh));
    }
};