class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i = 0;
        int j = grid[0].size()-1;
        
        int ans = 0;
        while(j>=0 and i<grid.size()){
            if(grid[i][j]<0)
            {
                ans+=(grid.size()-i);
                j--;
            }else
                i++;
                
        }
        return ans;
    }
};