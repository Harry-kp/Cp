class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){return a[1]<b[1];});
        vector<vector<int>> ans;
        int l = intervals[0][0],r = intervals[0][1];
        
        for(int i = 1;i<intervals.size();i++){
            if(r<intervals[i][0]){
                ans.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }else{
                l = min(l,intervals[i][0]);
                r = intervals[i][1];
            }
        }
        
        ans.push_back({l,r});
        return ans;
    }
};