class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool col = false,row = false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    if( i == 0)
                        row = true;
                    if(j == 0)
                        col = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0  and matrix[i][j]!=0){
                    if(matrix[0][0] and row)
                        matrix[i][j] = 0;
                }
                if(j == 0  and matrix[i][j]!=0){
                    if(matrix[0][0] and col)
                        matrix[i][j] = 0;
                }
                matrix[i][j] = (!matrix[i][0] or !matrix[0][j])?0:matrix[i][j];
                // cout<<matrix[i][j]<<" ";
                
            }
            // cout<<'\n';
                
        }
        
        
    }
};