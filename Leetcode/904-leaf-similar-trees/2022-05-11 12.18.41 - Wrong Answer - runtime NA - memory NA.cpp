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
    stack<int> st;
    bool ok;
    void dfs(TreeNode*r,bool check){
        if(!r)return ;
        if(!r->left && !r->right){
            if(check){
                if(!st.empty() and st.top() == r->val)
                    st.pop();
                else
                    ok=false;
            }else
                st.push(r->val);
            
            return ;
        }
        
        if(check)
        {
            dfs(r->right,check);
            dfs(r->left,check);
        }else{
            dfs(r->left,check);
            dfs(r->right,check);
        }
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        ok=true;
        dfs(root1,false);
        dfs(root2,true);
        return ok;
    }
};