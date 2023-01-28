class Solution {
public:
    pair<int,int> twoSum(vector<int> &dup,int i,int j,int sum1){
        
        return {-1,-1};
                
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,pair<int,int>>> s1;
        vector<vector<int>> ans;
        //if you want to retain original array
        vector<int> dup = nums;
        
        sort(dup.begin(),dup.end());
        pair<int,int> tmp;
        for(int i = 0;i<n-1;i++){
            int j = i+1,k = n-1;
            while(j<k){
                if(dup[j] + dup[k] + dup[i] == 0 and s1.find({dup[i],{dup[j],dup[k]}}) == s1.end()){
                s1.insert({dup[i],{dup[j],dup[k]}});
                ans.push_back({dup[i],dup[j],dup[k]});
                }
                
                if(dup[j] + dup[k]> -dup[i])
                    k--;
                else
                    j++;
            }
        }
        return ans;
        
    }
};