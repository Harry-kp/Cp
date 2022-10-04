class NumMatrix {
public:
     vector<vector<int>> rsq;
    NumMatrix(vector<vector<int>>& matrix) {
        rsq= matrix;
        
        int n = rsq.size();
        int m = rsq[0].size();
        
        for(int i = 1;i<n;i++){
            rsq[i][0]+=rsq[i-1][0];
        }
         for(int j = 1;j<m;j++){
            rsq[0][j]+=rsq[0][j-1];
        }
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                rsq[i][j] = rsq[i][j] + rsq[i-1][j]+rsq[i][j-1]-rsq[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = rsq[row2][col2];
        
        if(row1-1>=0)
            ans-=rsq[row1-1][col2];
        if(col1-1>=0)ans-=rsq[row2][col1-1];
        
        if(row1-1>=0 and col1-1>=0)
            ans+=rsq[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */