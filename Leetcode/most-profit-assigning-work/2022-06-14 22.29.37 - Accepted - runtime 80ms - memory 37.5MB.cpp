class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> jobs;
        
        for(int i = 0;i<profit.size();i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
        
        sort(worker.begin(),worker.end());
        sort(jobs.begin(),jobs.end());
        
        int ans = 0;
        
        int max1 = 0;
        int i = 0;
        int n = jobs.size();
        for(auto w:worker){
            while(i<n and w>=jobs[i].first)
            {
                max1 = max(max1,jobs[i].second);
                i++;
            }
            ans+=max1;
        }
        return ans;
    }
};