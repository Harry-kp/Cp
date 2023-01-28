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
    map<int,bool> bst;
    map<int,int> sum;
    
    int sum1(TreeNode * root,int ind){
        if(root == NULL)
            return 0;
        
        int ans = root->val + sum1(root->left,ind*2) + sum1(root->right,ind*2+1);
        sum[ind] = ans;
        return ans;
    }
    
    bool is_bst(TreeNode * root,int ind){
        static TreeNode * prev = NULL;
        if(root  == NULL)return true;
        
        bool ans = is_bst(root->left,ind*2);
        
        //check inorder condition
        if(prev and prev->val>=root->val)
        {
            ans = false;
        }
        prev = root;
        ans &= is_bst(root->right,ind*2+1);
        bst[ind] = ans;
        return ans;
    }
    
    
    int maxSumBST(TreeNode* root) {
        sum1(root,1);
        is_bst(root,1);
        int ans = 0;
        for(auto x:bst){
            if(x.second)
                ans = max(ans,sum[x.first]);
        }
        return ans;
        
    }
};