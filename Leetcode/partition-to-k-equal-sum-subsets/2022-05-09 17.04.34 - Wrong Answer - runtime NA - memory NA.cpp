class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        // cout<<sum%k<<'\n';
        if(sum%k)return false;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i = 0;i<k;i++)
            pq.push(0);
        sort(nums.begin(),nums.end(),greater<int>());
        for(auto x:nums){
            int y = pq.top();
            pq.pop();
            y=y+x;
            pq.push(y);
        }
        
        int part = sum/k;
        while(!pq.empty()){
            int x = pq.top();
            if(x == 0 or x!=part){
                return false;
            }
                // cout<<x<<'\n';/
            pq.pop();
        }
        return true;
    }
};