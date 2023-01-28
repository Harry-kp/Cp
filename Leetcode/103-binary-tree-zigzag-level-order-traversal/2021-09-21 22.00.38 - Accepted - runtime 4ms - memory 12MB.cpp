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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>  ans;
        vector<int> tmp_arr;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> tmp;
        q.push({root,0});
        int prev = 0,now;
        TreeNode * node;
        // int c = 0;
        while(!q.empty()){
            // c++;
            tmp = q.front();
            q.pop();
            now = tmp.second;
            node = tmp.first;
            // cout<<node->val<<" "<<now<<'\n';
            if(prev!=now){
                // prev = now;
                if(now%2 == 0)
                    reverse(tmp_arr.begin(),tmp_arr.end());
                ans.push_back(tmp_arr);
                tmp_arr.clear();
                tmp_arr.push_back(node->val);
            }else{
                
                tmp_arr.push_back(node->val);
            }
            
            prev = now;
            if(node->left!=NULL)
                q.push({node->left,now+1});
            if(node->right!=NULL)
                q.push({node->right,now+1});
            
        }
        // cout<<c<<'\n';
        if(now%2 == 1)
            reverse(tmp_arr.begin(),tmp_arr.end());
        ans.push_back(tmp_arr);
        return ans;
        
        
        
    }
};