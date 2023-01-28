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
    bool solve(TreeNode* r, int targetSum,int sum) {
        if(!r)
            return false;
        if(!r->left and !r->right){
            // cout<<sum<<'\n';
            return targetSum == sum+r->val;
            
        }
            
        sum+=r->val;
        return solve(r->left,targetSum,sum)||solve(r->right,targetSum,sum);
        
    }
    bool hasPathSum(TreeNode* r, int targetSum) {
        return solve(r,targetSum,0);
        
    }
};