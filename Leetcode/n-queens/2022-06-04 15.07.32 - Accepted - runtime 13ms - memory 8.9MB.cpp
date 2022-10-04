class Solution {
public:
    vector<vector<string>> ans;
    vector<string> util(vector<int> mask){
        
        int n = mask.size();
        vector<string> res(n);
        
        for(int i = 0;i<n;i++){
            string tmp = "";
            for(int j = 0;j<n;j++){
                tmp+='.';
            }
            tmp[mask[i]]='Q';
            res[i]=tmp;
        }
        return res;
        
    }
    
    void solve(int i,int n,vector<int> mask){
        if(i == n)
        {
            ans.push_back(util(mask));
            return ;
        }
        
       
        for(int j = 0;j<n;j++){
            bool ok = true;
            //check for same rows
            for(int k = 0;k<i;k++){
                if(mask[k] == j){
                    ok=false;
                    break;
                }
            }
            
            //check for  diagonal
            int k = i-1;
            int c=1;
            while(k>=0){
                if(mask[k]==(j-c)){
                    ok=false;
                    break;
                }
                
                if(mask[k] == (j + c)){
                    ok=false;
                    break;
                }
                   c++;
                k--;
            }
            if(ok)
            {
                mask.push_back(j);
                solve(i+1,n,mask);
                mask.pop_back();
            }
                
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        solve(0,n,{});
        return ans;
    }
};