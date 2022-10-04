class Solution {
public:
    bool isPowerOfThree(int n) {
        int ans = log(n)/log(3);
        cout<<ans<<'\n';
        if(n == pow(3,ans))return true;
        return false;
    }
};