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
    void solve(TreeNode* r, int d,int D,int val){
        if(!r)
            return;
        if(d == D){
            r->left  = new TreeNode(val,r->left,NULL);
            r->right = new TreeNode(val,NULL,r->right);
            return;
        }
        solve(r->left,d+1,D,val);
        solve(r->right,d+1,D,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        solve(root,1,depth-1,val);
        return root;
    }
};