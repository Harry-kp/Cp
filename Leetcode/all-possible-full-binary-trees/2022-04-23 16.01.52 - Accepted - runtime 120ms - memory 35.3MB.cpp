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
    vector<TreeNode*> solve(int n) {
        if(n==1){
            return {new TreeNode(0)};
        }
        
        vector<TreeNode*> ans;
        for(int i = 1;i<n;i+=2){
            vector<TreeNode*> l = solve(i);
            vector<TreeNode*> r = solve(n-i-1);
        
            for(auto l1:l)
                for(auto r1:r){
                    TreeNode* root = new TreeNode(0);
                    root->left = l1;
                    root->right = r1;
                    ans.push_back(root);
            }
    }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0)return {};
        
        return solve(n);
            
    }
};