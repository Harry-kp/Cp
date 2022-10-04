class Solution {
public:
    bool isPowerOfThree(int n) {
        bool sign = false;
        if(n<0)n*=-1;
        int ans = log(n)/log(3);
        // cout<<ans<<'\n';
        if(sign and ans%2 == 0)return false;
        if(n == pow(3,ans))return true;
        return false;
    }
};