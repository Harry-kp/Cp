class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int i,j;
        //transpose
        for( i = 0;i<n;i++)for( j = 0;j<m;j++)if(i<j)swap(matrix[i][j],matrix[j][i]);
        
        //
         j = 0;
        while(j<m/2){
            for(i = 0;i<n;i++)
                swap(matrix[i][j],matrix[i][m-j-1]);
            j++;
        }
    }
};