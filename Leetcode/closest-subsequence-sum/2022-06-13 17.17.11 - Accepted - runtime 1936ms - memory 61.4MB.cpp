class Solution {
public:
    vector<int> subset(vector<int> A){
        vector<int> res;
        int n = A.size();
        int tmp;
        for(int mask = 0;mask<(1<<n);mask++){
            tmp=0;
            for(int i = 0;i<n;i++){
                if((mask&(1<<i))!=0)
                    tmp+=A[i];
            }
            res.push_back(tmp);
        }
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int m = nums.size()/2;
        vector<int> l = subset(vector<int>(nums.begin(),nums.begin()+m));
        vector<int> r = subset(vector<int>(nums.begin() + m,nums.end()));
                               
        sort(r.begin(),r.end());
        int min1 = 1000000000;
        
        for(auto x:l){
            int y = goal-x;
            
            int z = lower_bound(r.begin(),r.end(),y)-r.begin();
            if(z<r.size())
                min1 = min(min1,abs(r[z]-y));
            if(z>0)
                min1 = min(min1,abs(r[z-1]-y));
            
            
        }
        return min1;
    }
};