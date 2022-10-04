class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int i,j;
        //transpose
        for( i = 0;i<n;i++)for( j = i+1;j<m;j++)swap(matrix[i][j],matrix[j][i]);
        
        //reverse
        for(i = 0;i<n;i++)
                reverse(matrix[i].begin(),matrix[i].end());
    }
};