class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)return false;
        
        return n == pow(3,log10(n)/log10(3));
    }
};