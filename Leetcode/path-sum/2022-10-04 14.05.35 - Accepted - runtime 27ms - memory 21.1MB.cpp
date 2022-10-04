class Solution {
public:
    bool solve(TreeNode* r, int targetSum,int sum) {
        if(!r)
            return false;
        if(!r->left and !r->right){
            return targetSum == sum+r->val;
            
        }
            
        sum+=r->val;
        return solve(r->left,targetSum,sum)||solve(r->right,targetSum,sum);
        
    }
    bool hasPathSum(TreeNode* r, int targetSum) {
        return solve(r,targetSum,0);
        
    }
};