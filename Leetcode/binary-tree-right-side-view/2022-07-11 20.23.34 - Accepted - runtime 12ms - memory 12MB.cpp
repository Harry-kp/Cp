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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        vector<int> res;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* u = q.front();
                if(i == n-1)
                    res.push_back(u->val);
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
                q.pop();
            }
            
        }
        return res;
    }
};