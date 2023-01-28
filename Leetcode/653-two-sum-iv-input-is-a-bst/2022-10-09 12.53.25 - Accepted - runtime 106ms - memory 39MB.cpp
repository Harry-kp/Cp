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
        
    unordered_set<int> s1;
    bool solve(TreeNode* r,int t){
        if(!r)return false;
        
        if(s1.count(t-r->val))return true;
        s1.insert(r->val);
        return solve(r->left,t)||solve(r->right,t);
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k);
    }
};