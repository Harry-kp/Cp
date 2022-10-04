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
    int solve(TreeNode*root,int mx){
        if(!root)
            return 0;

        int x = root->val;
        mx = x>mx?x:mx;
        return solve(root->left,mx)+solve(root->right,mx)+(x>=mx);
    }
    
    int goodNodes(TreeNode* root) {
        
        return solve(root,root->val);
    }
    
    Solution() {        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  }
};