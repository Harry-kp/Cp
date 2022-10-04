class Solution {
public:
    int solve(int i,priority_queue<int> mx,priority_queue<int,vector<int>,greater<int>> mn){
        if(i == 0)
            return mx.top()-mn.top();
        
        int ans = 2*1000000000;
        
        
        
        //change top min to top max
        priority_queue<int,vector<int>,greater<int>> mn1=mn;
        mn1.pop();
        mn1.push(mx.top());
        
        ans = min(ans,solve(i-1,mx,mn1));
        //change top max to top min
        mx.pop();
        mx.push(mn.top());
        ans = min(ans,solve(i-1,mx,mn));
        
        return ans;
        
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<5)
            return 0;
        priority_queue<int,vector<int>,greater<int>> mn;
        priority_queue<int> mx;
        for(auto x:nums)
        {
            mn.push(x);
            mx.push(x);
        }
        return solve(3,mx,mn);
    }
};