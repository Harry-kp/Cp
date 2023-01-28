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
    
    void solve(TreeNode* r,string& s){
        if(!r)return;
        
        s+="(";
        s+=to_string(r->val);
        solve(r->left,s);
        solve(r->right,s);
        s+=")";
        
    }
    string tree2str(TreeNode* root) {
        string res="";
        solve(root,res);
        res.pop_back();
        res.erase(res.begin());
        return res;
    }
};