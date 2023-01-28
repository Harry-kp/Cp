class Solution {
public:
    char a[5] = {'a','e','i','o','u'};
    int solve(int n,char prev){
        if(n == 0)return 1;
        
        int ans = 0;
        for(int i = 0;i<5;i++){
            if(a[i]>=prev)
                ans+=solve(n-1,a[i]);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        return solve(n,'a');
    }
};