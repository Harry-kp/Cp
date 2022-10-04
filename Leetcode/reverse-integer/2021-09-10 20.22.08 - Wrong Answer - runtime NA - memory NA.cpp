class Solution {
public:
    int reverse(int x) {
        int ans = 0,d;
        bool minus = (x<0);
        
        x = abs(x);
        while(x>0){
            d = x%10;
            if(ans>=214748364)return 0;
            ans*=10;
            ans+=d;
            x/=10;
        }
        return minus?ans*-1:ans;
    }
};