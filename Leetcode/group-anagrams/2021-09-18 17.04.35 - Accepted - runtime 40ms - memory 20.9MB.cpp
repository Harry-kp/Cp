class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        map<string,vector<string>> m1;
        vector<vector<string>> ans;
        string tmp;
        for(int i = 0;i<n;i++){
            tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            
            m1[tmp].push_back(strs[i]);
        }
        for(auto x:m1){
            ans.push_back(x.second);
        }
        return ans;
    }
};