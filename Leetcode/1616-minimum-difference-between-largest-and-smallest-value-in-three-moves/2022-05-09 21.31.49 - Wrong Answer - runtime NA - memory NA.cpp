class Solution {
public:
    int solve(int i,vector<int> a){
        if(i == 3)
        {
            int mx = -1000000000;
            int mn = 1000000000;
            for(auto x:a){
                mx = max(mx,x);
                mn= min(x,mn);
            }
            return mx-mn;
        }
        
        int ans = 1000000000*2;
        int n = a.size();
        int tmp = a[0];
        a[i]=a[n-i-1];
        ans = min(ans,solve(i+1,a));
        a[i] = tmp;
        a[n-i-1]=a[i];
        ans=min(ans,solve(i+1,a));
        return ans;
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<5)
            return 0;
        sort(nums.begin(),nums.end());
        return solve(0,nums);
    }
};