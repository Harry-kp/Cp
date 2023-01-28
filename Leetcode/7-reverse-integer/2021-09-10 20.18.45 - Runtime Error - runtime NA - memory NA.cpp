class Solution {
public:
    int reverse(int x) {
        int ans = 0,d;
        bool minus = (x<0);
        
        x = abs(x);
        while(x>0){
            d = x%10;
            ans*=10;
            ans+=d;
            if(ans>2e31-1)return 0;
            x/=10;
        }
        return minus?ans*-1:ans;
    }
};