class Solution {
public:
    int solve(int r,int c,const vector<vector<int>>& triangle){
        if(r == triangle.size())
            return 0;
        
        if(c>=triangle[r].size())
            return 1000000000;
        return triangle[r][c] + min(solve(r+1,c,triangle),solve(r+1,c+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0,0,triangle);
    }
};