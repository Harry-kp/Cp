class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0;i<numRows;i++){
            if(i == 0)ans[i].push_back(1);
            else{
                for(int j = 0;j<=i;j++){
                    if(j == 0 or j == i)
                    ans[i].push_back(1);
                    else{
                        ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                    }
                    
                }
            }
        }
        return ans;
    }
};