class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> m1;
        
        int ans = 0,l = 0,r = 0,n = s.size();
        
        while(r<n){
            
            
            if(m1.find(s[r]) != m1.end() and m1[s[r]]>=l){
               l = m1[s[r]];
                m1.erase(s[r]);
                l++;
            }
            ans = max(ans,r-l+1);
            m1.insert({s[r],r});
                r++;
        }
        return ans;
        
        
    }
};