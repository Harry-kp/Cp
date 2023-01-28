class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());

        vector<int> ans(q.size());
        partial_sum(nums.begin(),nums.end(),nums.begin());

        for(int i = 0;i<q.size();i++){
            int a = upper_bound(nums.begin(),nums.end(),q[i])-nums.begin(); 
            ans[i] = a;
        }
return ans;
    }
};