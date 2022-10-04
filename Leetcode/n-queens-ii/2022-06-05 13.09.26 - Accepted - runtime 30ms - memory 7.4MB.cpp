

class Solution {
public:
    int ans;
    void solve(int i,int n,vector<int> mask){
        if(i == n)
        {
            ans++;
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
    int totalNQueens(int n) {
        ans=0;
        solve(0,n,{});
        return ans;
    }
};