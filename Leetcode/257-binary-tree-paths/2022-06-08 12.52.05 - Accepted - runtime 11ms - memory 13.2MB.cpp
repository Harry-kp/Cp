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
    vector<string> ans;
    
    void solve(TreeNode* r,string p){
        if(!r){
            return ;
        }
        
        if(!r->left and !r->right){
            p+=to_string(r->val);
            ans.push_back(p);
            return;
        }
        
        p+=to_string(r->val);
        p+="->";
        solve(r->left,p);
        solve(r->right,p);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};