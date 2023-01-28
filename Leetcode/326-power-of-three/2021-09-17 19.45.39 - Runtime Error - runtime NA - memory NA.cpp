class Solution {
public:
    bool isPowerOfThree(int n) {
        int ans = log(n)/log(3);
            
        if(ans == 3^ans)return true;
        return false;
    }
};