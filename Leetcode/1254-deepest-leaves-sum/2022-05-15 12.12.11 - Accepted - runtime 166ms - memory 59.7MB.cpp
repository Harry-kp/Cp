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
    void solve(TreeNode*r,int l,int& ans,int& lvl){
        if(!r)return;
        if(!r->left and !r->right){
            if(l == lvl){
                ans+=r->val;
            }else if(l>lvl){
                ans=r->val;
                lvl=l;
            return;
            }
        }
        
        solve(r->left,l+1,ans,lvl);
        solve(r->right,l+1,ans,lvl);
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0,lvl=0;
        solve(root,0,ans,lvl);
        return ans;
    }
};