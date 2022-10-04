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
    
    vector<vector<int>> solve(TreeNode* root){
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        pair<TreeNode*,int> tmp;
        
        int prev = 0;
        vector<int> tmp_arr;
        while(!q.empty()){
            tmp = q.front();q.pop();
            
            if(prev!=tmp.second){
                ans.push_back(tmp_arr);
                prev = tmp.second;
                tmp_arr.clear();
            }
            tmp_arr.push_back(tmp.first->val);
            if(tmp.second%2 == 0){
                if(tmp.first->right)
                    q.push({tmp.first->right,tmp.second+1});
                if(tmp.first->left)
                    q.push({tmp.first->left,tmp.second+1});
            }else{
                if(tmp.first->left)
                    q.push({tmp.first->left,tmp.second+1});
                if(tmp.first->right)
                    q.push({tmp.first->right,tmp.second+1});
            }
            
        }
        ans.push_back(tmp_arr);
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        return solve(root);
    }
};