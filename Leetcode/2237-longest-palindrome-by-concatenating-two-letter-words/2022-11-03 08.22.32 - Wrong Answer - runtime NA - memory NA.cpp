class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> m1;
        for(auto x:words)
            m1[x]++;
        
        for(auto x:words){
            string rev_x = x;
            reverse(rev_x.begin(),rev_x.end());
            if(x == rev_x){
                ans+=m1[x];
                m1[x]= 0;
            }else{
                int c = min(m1[x],m1[rev_x]);
                m1[x]-=c;
                m1[rev_x]-=c;
                ans+=2*c;
            }
            
            
        }
        return ans*2;
    }
};