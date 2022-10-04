class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        
        for(auto e:edges){
            in[e[1]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0;i<n;i++){
            if(!in[i])
                ans.push_back(i);
        }
        return ans;
    }
};