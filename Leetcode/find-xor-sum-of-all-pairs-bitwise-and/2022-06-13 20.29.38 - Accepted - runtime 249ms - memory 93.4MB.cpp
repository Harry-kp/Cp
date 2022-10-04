class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        
        int xor2 = 0;
        
        for(auto x:arr2){
            xor2^=x;
        }
        
        int ans = 0;
        for(auto x:arr1){
            ans = ans^(x&(xor2));
        }
        return ans;
    }
};