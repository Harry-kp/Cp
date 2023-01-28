class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0,cnt = 32;;
        while(cnt--){
            ans = ans<<1;
            if(n&1 == 1)
                ans^=1;
            n>>=1;
        }
        return ans;
    }
};