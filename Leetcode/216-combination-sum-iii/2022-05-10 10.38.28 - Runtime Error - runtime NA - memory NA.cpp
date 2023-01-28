class Solution {
public:
    int bits(int n){
        if(!n)return 0;
        return (n%2) + bits(n/2);
    }
    
    int sum(int mask){
        int s = 0;
        for(int i = 0;i<9;i++){
            if(mask&(1<<i)){
                s+=i+1;
            }
                    
        }
        return s;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        for(int mask = 0;mask<(1<<n);mask++){
            if(bits(mask) == k and sum(mask)==n){
                cout<<mask<<'\n';
                vector<int> tmp;
                
                for(int i = 0;i<9;i++){
                    if(mask&(1<<i)){
                        tmp.push_back(i+1);}
                    
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};