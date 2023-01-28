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
    vector<double> avg;
    vector<int> count;
    
    void traverse(TreeNode* r,int l){
        
        if(!r)return ;
        
        if(l>avg.size())
        {
            avg.push_back(r->val);
            count.push_back(1);
        }else if(r->val<2147483647)
        {
            avg[l-1]+=r->val;
            count[l-1]++;
        }
        
        traverse(r->left,l+1);
        traverse(r->right,l+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        traverse(root,1);
        for(int i = 0;i<avg.size();i++)
            avg[i]=avg[i]/count[i];
        
        return avg;
    }
};