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
    int maxDepth(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        if(root == NULL)return 0;
        int ans = 0;
        q.push({root,1});
        TreeNode * tmp;
        while(!q.empty()){
            tmp = q.front().first;
            ans = max(ans,q.front().second);
            
            if(tmp->left)
                q.push({tmp->left,ans + 1});
            if(tmp->right)
                q.push({tmp->right,ans + 1});
            q.pop();   
        }
        return ans;
    }
};