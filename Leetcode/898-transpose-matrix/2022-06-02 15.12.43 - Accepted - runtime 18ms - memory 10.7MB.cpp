class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        int r = m.size(),c=m[0].size();
        
        vector<vector<int>> res(c,vector<int>(r));
        
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++){
                res[j][i] = m[i][j];
            }
        return res;
    }
};